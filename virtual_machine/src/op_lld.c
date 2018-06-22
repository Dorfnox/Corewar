/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:07:58 by dmontoya         ###   ########.fr       */
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
	uint16_t		idx;

	idx = process->curr_pc->index;
	if (!parse_encoding_byte(core, process) || EB0 < 2 || EB1 != 1 || EB2)
	{
		move_pc_by_encoding_byte(core, process, 0, 2);
		return ;
	}
	if (!parse_arguments(core, process, 0))
		return ;
	if (EB0 == DIRECT)
		ft_memcpy(REG[ARG10], ARG0, 4);
	else if (EB0 == INDIRECT)
	{
		idx = get_index_unchained(idx, ARG00, ARG01);
		if (ARG00 >> 7)
			write_board_to_register(REG[ARG10], core->node_addresses_rev[idx]);
		else
			write_board_to_register(REG[ARG10], core->node_addresses[idx]);
	}
	process->carry = !smash_bytes(REG[ARG10]);
}
