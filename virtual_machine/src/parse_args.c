/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:17:47 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 18:17:57 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Utility functions for helping control the start of the game
*/

uint8_t	parse_arguments(t_corewar *core, t_process *process,
			uint8_t two_bytes)
{
	uint8_t success;

	success = 1;
	if (!(core->parse_arg[core->encoding_byte[0]](core, process, 0, two_bytes)))
		success = 0;
	if (!(core->parse_arg[core->encoding_byte[1]](core, process, 1, two_bytes)))
		success = 0;
	if (!(core->parse_arg[core->encoding_byte[2]](core, process, 2, two_bytes)))
		success = 0;
	return (success);
}

uint8_t	parse_nothing(t_corewar *core, t_process *process,
			uint8_t i, uint8_t two_bytes)
{
	(void)core;
	(void)process;
	(void)i;
	(void)two_bytes;
	return (1);
}

uint8_t	parse_register(t_corewar *core, t_process *process,
			uint8_t i, uint8_t two_bytes)
{
	(void)two_bytes;
	core->args[i][0] = process->curr_pc->value;
	process->curr_pc = process->curr_pc->next;
	return (!((core->args[i][0] > REG_NUMBER) || (core->args[i][0] < 1)));
}

uint8_t	parse_direct(t_corewar *core, t_process *process,
			uint8_t i, uint8_t two_bytes)
{
	core->args[i][0] = process->curr_pc->value;
	core->args[i][1] = process->curr_pc->next->value;
	core->args[i][2] = process->curr_pc->next->next->value;
	core->args[i][3] = process->curr_pc->next->next->next->value;
	process->curr_pc = (two_bytes) ? process->curr_pc->next->next :
		process->curr_pc->next->next->next->next;
	return (1);
}

uint8_t	parse_indirect(t_corewar *core, t_process *process,
			uint8_t i, uint8_t two_bytes)
{
	(void)two_bytes;
	core->args[i][0] = process->curr_pc->value;
	core->args[i][1] = process->curr_pc->next->value;
	core->args[i][2] = 0;
	core->args[i][3] = 0;
	process->curr_pc = process->curr_pc->next->next;
	return (1);
}
