/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/18 18:11:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "libft.h"
# include "op.h"

/*
**  MACROS
*/

# define USAGE					"usage: <>"
# define BYTE_TO_FILE(x)		ft_putchar_fd(x,assembler->fd)
# define CAPACITY				30


/*
**	Token types
*/

# define NONE					0
# define LABEL					1
# define OPERATION				2
# define PARAMETER				3
# define PARAM_SEPARATOR		4
# define COMMENT				5
# define MATH					6
# define HEADER					7
# define EOL					-1
# define EMPTY					-2

/*
**	Token subtypes
*/

#define HEADER_NAME				1
#define HEADER_COMMENT			2

# define LIVE					1
# define LD						2
# define ST						3
# define ADD					4
# define SUB					5
# define AND					6
# define OR						7
# define XOR					8
# define ZJUMP					9
# define LDI					10
# define STI					11
# define FORK					12
# define LLD					13
# define LLDI					14
# define LFORK					15
# define AFF					16

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

/*
**  STRUCTURES
*/

typedef	struct			s_input
{
	char				*s;
	size_t				len;
	size_t				index;
	size_t				line_n;
	char				current_char;
}						t_input;

typedef	struct			s_token
{
	int8_t				type;
	uint8_t				subtype;
	char				*value;
}						t_token;

typedef struct			s_ast
{
	uint8_t				op;
	uint8_t				ecb;
	uint8_t				len_params;
	t_token				*params;
	uint8_t				bytes;
	struct s_ast		*next;
}						t_ast;

typedef struct			s_label_item
{
	char				*key;
	uint32_t			byte_start;
	struct s_label_item	*next;
}						t_label_item;

typedef struct			s_labels
{
	t_label_item		**items;
	size_t				capacity;
}						t_labels;

typedef struct			s_ops
{
	t_ast				*first;
	t_ast				*last;
	t_labels			*labels;
	uint32_t			total_bytes;
	uint16_t			number_of_ops;
}						t_ops;

typedef struct			s_asm
{
    int					fd;
    char				*input_file_name;
    char				*input_content;
	char				*output_file_name;
	t_header			*header;	
	t_ops				*ops;
	void				(*op_handler[17])(t_input *line, t_ops *ops, uint8_t opcode);
}						t_asm;

/*
**  Main functions
**	---------------------------------------------------------------------------
*/

t_asm					*init_asm(void);
void					verify_input(int ac, char **av, t_asm *assembler);


void					parse_input(t_asm *assembler);
void					parse_operations(t_asm *assembler, t_input *line, t_token *current_token, char *label_carry);
void					parse_header(t_asm *assembler, t_input *line, t_token *current_token, int *name_set, int *comment_set);

/*
**	Tokenizer functions
**	---------------------------------------------------------------------------
*/

t_token					*get_next_token(t_input *line);
void					get_token_type(t_token *token);
char					*parse_value(t_input *line);

uint8_t					check_if_header(char *s);

int8_t					token_is_label(char *s);
void					remove_label_char(char **s);

void					init_op_handler(t_asm *assembler);
uint8_t					compare_to_ops(char *s);
void					unknown_(t_input *line, t_ops *ops, uint8_t op_code);
void					live_(t_input *line, t_ops *ops, uint8_t op_code);
void					ld_lld_(t_input *line, t_ops *ops, uint8_t op_code);
void					st_(t_input *line, t_ops *ops, uint8_t op_code);
void					add_sub_(t_input *line, t_ops *ops, uint8_t op_code);
void					and_or_xor_(t_input *line, t_ops *ops, uint8_t op_code);
void					zjump_fork_lfork_(t_input *line, t_ops *ops, uint8_t op_code);
void					ldi_lldi_(t_input *line, t_ops *ops, uint8_t op_code);
void					sti_(t_input *line, t_ops *ops, uint8_t op_code);
void					aff_(t_input *line, t_ops *ops, uint8_t op_code);

t_token					*get_params(t_input *line, uint8_t len_tokens);
uint8_t					compare_to_params(char *s);
uint8_t					verify_if_register(char *s);
uint8_t					verify_if_direct(char *s);
uint8_t					verify_if_indirect(char *s);
uint8_t					create_ecb(t_token *tokens, uint8_t len_tokens);

void					advance(t_input *line);
void					skip_whitespaces(t_input *line);
int8_t					char_is_separator(char c);
void					remove_comment(char **s);

/*
**	Hexdump function
**	---------------------------------------------------------------------------
*/

void					create_bytecode(t_asm *assembler);
void					write_header(int fd, t_header *header);
void					write_ops(int fd, t_ops *ops, t_labels *labels);
void					write_params(int fd, t_ast *operation, t_labels *labels);
void					write_bytes(int fd, uintmax_t num, uint8_t bytes);

/*
**	Utility functions
**	---------------------------------------------------------------------------
*/

void					asm_error(int error_code, char *error_message);
int						is_space(char c);
int32_t					char_at(char *s, char c, int32_t start);

t_ast					*dequeue_op(t_ops *queue);
void					enqueue_op(t_ops *queue, t_ast *node);
t_ast					*create_ast(uint8_t op, uint8_t ecb, uint8_t bytes, t_token *params, uint8_t len_params);
t_ops					*init_op_queue(void);
uint8_t					op_queue_is_empty(t_ops *queue);

size_t					hash(char *label);
t_labels				*labelsInit(size_t capacity);
int8_t					labelsInsert(t_labels *dict, char *key, uint32_t byte_start);
uint32_t				labelsSearch(t_labels *dict, char *key);

#endif
