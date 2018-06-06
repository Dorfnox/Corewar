/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x09 - Z JUMP
**	- - - - - - - - - -
**	Takes an Index as a parameter and jumps to the current PC + index value
**
**	CANNOT be followed by a parameter encoding byte
**
**	WILL wait zjmp's wait time if parameter is valid or invalid
**
**	NOTE: MODIFIED BY THE CARRY
**	If carry == 1, make the jump.
**	If carry == null (0), ONLY wait
*/

void		zjmp_(t_corewar *core, t_process *process)
{
	uint8_t jump_index_a;
	uint8_t jump_index_b;
	uint16_t index;

	if (process->carry)
	{
		jump_index_a = (uint8_t)read_from_board(process->curr_pc->next, 1);
		jump_index_b = (uint8_t)read_from_board(process->curr_pc->next->next, 1);
		index = get_index(process->curr_pc->index, jump_index_a, jump_index_b);
		process->curr_pc = core->node_addresses[index];
	}
}
