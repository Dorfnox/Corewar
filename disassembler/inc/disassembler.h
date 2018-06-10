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

# define CHECK_EXTENSION_A (f[flen - 1] == 'r' && f[flen - 2] == 'o')
# define CHECK_EXTENSION_B (f[flen - 3] == 'c' && f[flen - 4] == '.')
# define CHECK_EXTENSION ((CHECK_EXTENSION_A) || (CHECK_EXTENSION_B))

typedef struct	s_instruction
{
	char		instr;
}				t_instruction;

void			disassembler_exit(char *message);
void			filename_validation(char *f);
void			content_validation(char *f, uint8_t **c, size_t *c_size);

void			disassemble_contents(char *file, uint8_t *c, size_t c_size);
void			write_name_and_comment_to_file(int fd, uint8_t *c);
void			write_instructions_to_file(int fd, uint8_t *c, size_t c_size);

#endif
