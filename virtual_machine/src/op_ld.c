/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x02 - LOAD
**	- - - - - - - - - -
**	Loads a value into a register, with a % IDX_MOD restriction
**
**	2 Parameters: 2nd must be a register (NOT THE PC)
*/

void		ld_(t_corewar *core, t_process *process)
{
	uint16_t		index;

	index = process->curr_pc->index;
	if (!parse_encoding_byte(process))
		return ;
	if ((EB0 < 2 || EB1 != 1 || EB2))
		return;
	if (!parse_arguments(process))
		return ;
	if (EB0 == DIRECT)
		ft_memcpy(process->reg[process->args[1][0]], process->args[0], 4);
	else if (EB0 == INDIRECT)
	{
		index = get_index(index, process->args[0][0], process->args[0][1]);
		write_board_to_register(process->reg[process->args[1][0]], core->node_addresses[index]);
	}
//	mvprintw(0, 0, "Reg value: %x\n", process->reg[process->args[1][0]]);
	process->carry = !smash_bytes(process->reg[process->args[1][0]]);
//	mvprintw(1, 0, "Reg value: %x\n", !smash_bytes(process->reg[process->args[1][0]]));
//	refresh();
	//ft_printf("register %u is now: %x%x%x%x\n", process->args[1][0],
	//	process->reg[process->args[1][0]][0], //debug
	//	process->reg[process->args[1][0]][1], //debug
	//	process->reg[process->args[1][0]][2],
	//	process->reg[process->args[1][0]][3]);
}
