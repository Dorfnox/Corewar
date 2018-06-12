/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/06/11 17:27:11 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef	OP_H
# define OP_H

# define OP_SIZE				1
# define ECB_SIZE				1
# define IND_SIZE				2
# define REG_SIZE				1
# define DIR_SIZE_0				4
# define DIR_SIZE_1				2


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define REGISTER_CHAR			'r'

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define COMMENT_DELIMITER_CHAR	'\"'

# define REG_NUMBER				16


# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
** Header
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					t_header;

/*
**	Token macros
*/

# define NONE					0
# define LABEL					1
# define OPERATION				2
# define PARAMETER				3
# define PARAM_SEPARATOR		4
# define COMMENT				5
# define MATH					6
# define EOL					-1
# define EMPTY					-2

/*
**	Operation codes
*/

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

#endif