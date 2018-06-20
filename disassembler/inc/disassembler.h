/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/06 13:01:17 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLER_H
# define DISASSEMBLER_H

# include <sys/stat.h>
# include "libft.h"

# define DIS_USAGE "usage: ./dsm file.cor\nmust use a valid .cor file"

# define D_EXIT(a) disassembler_exit((a))

# define FILE_ERR_MESSAGE_A "dsm: Invalid File: '\033[0;93m"
# define FILE_ERR_MESSAGE_B ft_str256(3, FILE_ERR_MESSAGE_A, f, "\033[0m' ")
# define FILE_ERR(a) D_EXIT(ft_str256(2, FILE_ERR_MESSAGE_B, (a)))

# define VAL_ERR_MESSAGE "dsm: Invalid Byte Code: "
# define VAL_ERR(a) D_EXIT(ft_str256(2, VAL_ERR_MESSAGE, (a)))

# define DIS_ERR_MESSAGE "dsm: "
# define DIS_ERR(a) D_EXIT(ft_str256(2, DIS_ERR_MESSAGE, (a)))

# define INSTR_ERR_MESSAGE "dsm: Invalid Instruction: "
# define INSTR_ERR(a) D_EXIT(ft_str256(2, INSTR_ERR_MESSAGE, (a)))

# define CHECK_EXTENSION_A (f[flen - 1] == 'r' && f[flen - 2] == 'o')
# define CHECK_EXTENSION_B (f[flen - 3] == 'c' && f[flen - 4] == '.')
# define CHECK_EXTENSION ((CHECK_EXTENSION_A) || (CHECK_EXTENSION_B))

# define IS_INVALID_REGISTER(a) ((a) > 16 || (a) == 0)

# define REG_NUMBER 16

# define EB0 eb[0]
# define EB1 eb[1]
# define EB2 eb[2]
# define BAD_EB eb[3]

// # define ARG00 arg[0][0]
// # define ARG01 arg[0][1]
// # define ARG02 arg[0][2]
// # define ARG03 arg[0][3]

// # define ARG10 arg[1][0]
// # define ARG11 arg[1][1]
// # define ARG12 arg[1][2]
// # define ARG13 arg[1][3]

// # define ARG20 arg[2][0]
// # define ARG21 arg[2][1]
// # define ARG22 arg[2][2]
// # define ARG23 arg[2][3]

char			*g_filename;

enum
{
				REGISTER = 1,
				DIRECT,
				INDIRECT
};

typedef struct	s_operation
{
	uint16_t	(*instruct)(int fd, struct s_operation *op, uint8_t *c);
	char		name[6];
}				t_operation;

void			disassembler_exit(char *message);
void			filename_validation(char *f);
void			content_validation(char *f, uint8_t **c, size_t *c_size);

void			disassemble_contents(char *file, uint8_t *c, size_t c_size);
void			write_name_and_comment_to_file(int fd, uint8_t *c);
void			write_instructions_to_file(int fd, uint8_t *c, size_t c_size);

void       		init_operations(t_operation *op);
void			init_wait_times(t_operation *op);
void        	init_instruction_names(t_operation *op);

uint8_t			*parse_encoding_byte(uint8_t content);
void			write_instruction(int fd, t_operation *op);
void			write_reg(int fd, uint8_t reg, int comma);
void			write_dir(int fd, uint8_t *val, int len, int comma);

uint16_t		math_(int fd, t_operation *op, uint8_t *content);

uint16_t		live_(int fd, t_operation *op, uint8_t *content);
uint16_t		zjmp_(int fd, t_operation *op, uint8_t *content);
uint16_t		fork_(int fd, t_operation *op, uint8_t *content);
uint16_t		lfork_(int fd, t_operation *op, uint8_t *content);

uint16_t		st_(int fd, t_operation *op, uint8_t *content);

#endif
