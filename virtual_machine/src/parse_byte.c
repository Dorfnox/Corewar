/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:47:54 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:15:55 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Processes the encoding byte and moves the curr_pc to the next node
**	Returns 1 = success, 0 = FAILURE
*/

uint8_t		parse_encoding_byte(t_corewar *core, t_process *process)
{
	uint8_t encoding_byte;

	encoding_byte = process->curr_pc->next->value;
	process->curr_pc = process->curr_pc->next->next;
	core->encoding_byte[0] = (encoding_byte >> 6) & 0b11;
	core->encoding_byte[1] = (encoding_byte >> 4) & 0b11;
	core->encoding_byte[2] = (encoding_byte >> 2) & 0b11;
	return (!(encoding_byte > 0xF8 || (encoding_byte & 0b11) > 0));
}

/*
**	Processes an encoding byte and moves the pc
*/

void		move_pc_by_encoding_byte(t_corewar *core, t_process *process,
	uint8_t read_two_bytes, uint8_t args)
{
	uint8_t		i;

	i = -1;
	while (++i < args)
	{
		if (core->encoding_byte[i] == REGISTER)
			process->curr_pc = process->curr_pc->next;
		else if (core->encoding_byte[i] == DIRECT)
		{
			if (read_two_bytes)
				process->curr_pc = process->curr_pc->next->next;
			else
				process->curr_pc = process->curr_pc->next->next->next->next;
		}
		else if (core->encoding_byte[i] == INDIRECT)
			process->curr_pc = process->curr_pc->next->next;
	}
}
