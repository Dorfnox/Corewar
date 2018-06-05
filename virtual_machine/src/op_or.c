/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:37 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x07 - OR
**	- - - - - - - - - -
**	Takes 3 parameters. param 3 is ALWAYS a register. stores the | of first two
**	into third-parameter's register
**
**	NOTE: MODIFIES THE CARRY
*/

void		or_(t_corewar *core, t_process *process)
{
	uint16_t	index;
	uint32_t	a;
	uint32_t	b;
	uint32_t	or_result;

	DB("or-ing");
	index = process->curr_pc->index;
	if (!parse_encoding_byte(process))
		return ;
	if (EB0 == 0 || EB1 == 0 || EB2 != REGISTER)
		return ;
	if (!parse_arguments(process) && !(process->carry = 0))
		return ;
	a = get_or_args(core, process, index, 0);
	b = get_or_args(core, process, index, 1);
	or_result = a | b;
	ft_printf("or result: %.8x\n", or_result);
	process->reg[process->args[2][0]][0] = (uint8_t)(or_result >> 24);
	process->reg[process->args[2][0]][1] = (uint8_t)(or_result >> 16);
	process->reg[process->args[2][0]][2] = (uint8_t)(or_result >> 8);
	process->reg[process->args[2][0]][3] = (uint8_t)(or_result >> 0);
}

uint32_t	get_or_args(
	t_corewar *core,
	t_process *process,
	uint16_t index,
	uint8_t arg_num)
{
	if (process->encoding_byte[arg_num] == REGISTER)
		return (smash_bytes(process->reg[process->args[arg_num][0]]));
	else if (process->encoding_byte[arg_num] == DIRECT)
		return (smash_bytes(process->args[arg_num]));
	else if (process->encoding_byte[arg_num] == INDIRECT)
		return (read_from_board(core->node_addresses[
			get_index(index, process->args[arg_num][0], process->args[arg_num][1])]));
	return (0);
}