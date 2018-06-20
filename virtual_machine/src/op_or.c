/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:08:46 by dmontoya         ###   ########.fr       */
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

	index = process->curr_pc->index;
	if (!parse_encoding_byte(process) ||
		EB0 == 0 || EB1 == 0 || EB2 != REGISTER)
	{
		move_pc_by_encoding_byte(process, 0, 3);
		return ;
	}
	if (!parse_arguments(process, 0))
		return ;
	a = get_or_args(core, process, index, 0);
	b = get_or_args(core, process, index, 1);
	or_result = a | b;
	REG[ARG20][0] = (uint8_t)(or_result >> 24);
	REG[ARG20][1] = (uint8_t)(or_result >> 16);
	REG[ARG20][2] = (uint8_t)(or_result >> 8);
	REG[ARG20][3] = (uint8_t)(or_result >> 0);
	process->carry = !smash_bytes(REG[ARG20]);
}

uint32_t	get_or_args(
	t_corewar *core,
	t_process *process,
	uint16_t index,
	uint8_t arg_num)
{
	t_board_node	*location;
	uint32_t		ret;

	ret = 0;
	if (process->encoding_byte[arg_num] == REGISTER)
		ret = smash_bytes(REG[process->args[arg_num][0]]);
	else if (process->encoding_byte[arg_num] == DIRECT)
		ret = smash_bytes(process->args[arg_num]);
	else if (process->encoding_byte[arg_num] == INDIRECT)
	{
		index = get_index(index,
			process->args[arg_num][0],
			process->args[arg_num][1]);
		if (process->args[arg_num][0] >> 7)
			location = core->node_addresses_rev[index];
		else
			location = core->node_addresses[index];
		ret = read_from_board(location, 4);
	}
	return (ret);
}
