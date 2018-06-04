/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 00:22:31 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "libft.h"

/*
**  MACROS
*/

#define	USAGE					"usage: <>"

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

# define IND_CODE				3
# define REG_CODE				1
# define DIR_CODE				2

#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define REGISTER_CHAR			'r'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
#define CMD_DELIMITER_CHAR		'\"'

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**	Arguments
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**	Header
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
**	Token macros
*/

# define NONE					0
# define LABEL					1
# define OPERATION				2
# define PARAMETER				3
# define EOL					-1

/*
**	Operation codes
*/

# define LIVE						1
# define LD							2
# define ST							3
# define ADD						4
# define SUB						5
# define AND						6
# define OR							7
# define XOR						8
# define ZJUMP						9
# define LDI						10
# define STI						11
# define FORK						12
# define LLD						13
# define LLDI						14
# define LFORK						15
# define AFF						16

/*
**  STRUCTURES
*/

typedef	struct			s_input
{
	char				*s;
	size_t				len;
	size_t				index;
	char				current_char;
}						t_input;

typedef struct			s_header
{
	uint32_t			magic;
	uint8_t				prog_name[PROG_NAME_LENGTH + 1];
	uint32_t			prog_size;
	uint8_t				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef	struct			s_token
{
	uint8_t				type;
	char				*value;
	uint8_t				subtype;
}						t_token;

typedef struct			s_ast
{
	t_token				token;
	char				*label;				
	uint8_t				ecb;
	t_token				params[3];
	struct s_ast		*next;
}						t_ast;

typedef struct			s_ops
{
	//				pointer_to_start_of_ops
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
}						t_asm;

/*
**  FUNCTIONS
*/



void	asm_error(int error_code, char *error_message);

#endif
