/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:22 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0d - LONG LOAD
**	- - - - - - - - - -
**	Loads a value into a register, but without a % IDX_MOD restriction
**
**	2 Parameters: 2nd must be a register (NOT THE PC)
**
**	NOTE: MODIFIES THE CARRY
*/

void		lld_(t_corewar *core, t_process *process)
{
	t_board_node		*index;

	index = process->curr_pc;
	parse_encoding_byte(process);
	if ((EB0 < 2 || EB1 != 1 || EB2) && !(process->carry = 0))
		return;
	if (!parse_arguments(process))
		return ;
	if (EB0 == DIRECT)
		ft_memcpy(process->reg[process->args[1][0]], process->args[0], 4);
	else if (EB0 == INDIRECT)
	{
		index = core->node_addresses[(index->index + ((smash_bytes(process->args[0]) >> 16))) % MEM_SIZE];
		write_board_to_register(process->reg[process->args[1][0]], index);
	}
	process->carry = !smash_bytes(process->reg[process->args[1][0]]);
	//ft_printf("register %u is now: %x%x%x%x\n", process->args[1][0],
	//	process->reg[process->args[1][0]][0], //debug
	//	process->reg[process->args[1][0]][1], //debug
	//	process->reg[process->args[1][0]][2],
	//	process->reg[process->args[1][0]][3]);
}
