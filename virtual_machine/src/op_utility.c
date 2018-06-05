/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 22:36:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Utility functions for helping control the start of the game
*/

int		parse_arguments(t_process *process)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (process->encoding_byte[i] == 1)
		{
			process->args[i][0] = process->curr_pc->value;
			process->curr_pc = process->curr_pc->next;
			if (process->args[i][0] > 16 || process->args[i][0] < 1)
				return 0;
		}
		else if (process->encoding_byte[i] == 2)
		{
			process->args[i][0] = process->curr_pc->value;
			process->args[i][1] = process->curr_pc->next->value;
			process->args[i][2] = process->curr_pc->next->next->value;
			process->args[i][3] = process->curr_pc->next->next->next->value;
			process->curr_pc = process->curr_pc->next->next->next->next;
		}
		else if (process->encoding_byte[i] == 3)
		{
			process->args[i][0] = process->curr_pc->value;
			process->curr_pc = process->curr_pc->next; 
			process->args[i][1] = process->curr_pc->value;
			process->curr_pc = process->curr_pc->next;
		}
	}
	return 1;
}

void		parse_encoding_byte(t_process *process)
{
	uint8_t encoding_byte;

	encoding_byte = process->curr_pc->next->value;
	if (encoding_byte > 0xF8 || (encoding_byte & 0b111) > 0)
	{
		process->carry = 0;
		process->curr_pc = process->curr_pc->next->next;
		return; // Return invalid int?
	}
	process->encoding_byte[0] = (encoding_byte >> 6) & 0b11;
	process->encoding_byte[1] = (encoding_byte >> 4) & 0b11;
	process->encoding_byte[2] = (encoding_byte >> 2) & 0b11;
	process->curr_pc = process->curr_pc->next->next;
}

void		first_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}

void		bad_(t_corewar *core, t_process *process)
{
	(void)core;
	process->curr_pc = process->curr_pc->next;
}