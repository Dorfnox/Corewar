/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/05 17:27:15 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		is_space(char c)
{
	return ((c == ' ' || c == '\t') ? (1) : (0));
}

void	handle_whitespace(t_input *line)
{
	while (line->current_char && is_space(line->current_char))
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
	new_asm->ops = init_op_queue();
	init_op_handler(new_asm);
	return (new_asm);
}

void	init_op_handler(t_asm *assembler)
{
	assembler->op_handler[0] = &handle_live;
	assembler->op_handler[1] = &handle_live;
	assembler->op_handler[2] = &handle_live;
	assembler->op_handler[3] = &handle_live;
	assembler->op_handler[4] = &handle_live;
	assembler->op_handler[5] = &handle_live;
	assembler->op_handler[6] = &handle_live;
	assembler->op_handler[7] = &handle_live;
	assembler->op_handler[8] = &handle_live;
	assembler->op_handler[9] = &handle_live;
	assembler->op_handler[10] = &handle_live;
	assembler->op_handler[11] = &handle_live;
	assembler->op_handler[12] = &handle_live;
	assembler->op_handler[13] = &handle_live;
	assembler->op_handler[14] = &handle_live;
	assembler->op_handler[15] = &handle_live;
	assembler->op_handler[16] = &handle_live;
}
