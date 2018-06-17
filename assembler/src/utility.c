/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/16 15:50:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		is_space(char c)
{
	return ((c == ' ' || c == '\t') ? (1) : (0));
}

void	skip_whitespaces(t_input *line)
{
	while (char_is_separator(line->current_char))
		advance(line);
}

void	verify_input(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		asm_error(1, USAGE);
	len = ft_strlen(av[1]);
	if (len < 3  || av[1][len - 2] != '.' || av[1][len - 1] != 's')
		asm_error(1, USAGE);
}

void	asm_error(int error_code, char *error_message)
{
	if (error_message)
		write(2, error_message, ft_strlen(error_message));
	write(1, "\n", 1);
	exit(error_code);
}

t_asm	*init_asm(void)
{
	t_asm *new_asm;

	new_asm = (t_asm *)ft_memalloc(sizeof(t_asm));
	new_asm->header = (t_header *)ft_memalloc(sizeof(t_header));
	ft_memset(new_asm->header, 0, sizeof(new_asm->header));
	new_asm->ops = init_op_queue();
	init_op_handler(new_asm);
	return (new_asm);
}

void	init_op_handler(t_asm *assembler)
{
	assembler->op_handler[0] = &unknown_;
	assembler->op_handler[1] = &live_;
	assembler->op_handler[2] = &ld_lld_;
	assembler->op_handler[3] = &st_;
	assembler->op_handler[4] = &add_sub_;
	assembler->op_handler[5] = &add_sub_;
	assembler->op_handler[6] = &and_or_xor_;
	assembler->op_handler[7] = &and_or_xor_;
	assembler->op_handler[8] = &and_or_xor_;
	assembler->op_handler[9] = &zjump_fork_lfork_;
	assembler->op_handler[10] = &ldi_lldi_;
	assembler->op_handler[11] = &sti_;
	assembler->op_handler[12] = &zjump_fork_lfork_;
	assembler->op_handler[13] = &ld_lld_;
	assembler->op_handler[14] = &ldi_lldi_;
	assembler->op_handler[15] = &zjump_fork_lfork_;
	assembler->op_handler[16] = &aff_;
}

int8_t	char_is_separator(char c)
{
	if (!c || c == SEPARATOR_CHAR ||
			c == COMMENT_CHAR || ft_iswhitespace(c))
		return (1);
	return (0);
}

int8_t	token_is_label(char *s)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = -1;
	if (len > 1 && s[len - 1] == LABEL_CHAR)
	{
		while (++i < len - 1)
		{
			if (!(s[i] >='a' && s[i] <= 'z') && 
				!(s[i] >= '0' && s[i] <= '9') &&
				s[i] != '_')
				return (0);
		}
		return (1);
	}
	return (0);
}

// int8_t	token_is_parameter(char *s, size_t len)
// {
	
// }

void	remove_label_char(char **s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(*s);
	new_s = ft_strsub(*s, 0, len - 1);
	ft_strdel(s);
	*s = new_s;
}

size_t	char_at(char *s, char c, size_t start)
{
	if (s)
	{
		while (s[start])
		{
			if (s[start] == c)
				return (start);
			start++;
		}
	}
	return (-1);
}
