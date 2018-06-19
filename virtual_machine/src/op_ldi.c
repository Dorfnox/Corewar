/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0a - LOAD INDEX
**	- - - - - - - - - -
**	Loads an indexed value into a register, WITH a % IDX_MOD restriction
**
**	Takes 3 parameters (2 indexes, 1 registry), adds first two, and puts result
**	into the third-parameter's register
**
**	REG_SIZE bytes are read at the sum of the first two indexes, then loaded
**	into whatever register is in the third parameter
**
**	Direct number in this function is 2 bytes
**
*/

void		ldi_(t_corewar *core, t_process *process)
{
	uint32_t 		a;
	uint32_t 		b;
	uint16_t 		index;
	t_board_node	*location;

	a = 0;
	b = 0;
	index = process->curr_pc->index;
	if (!parse_encoding_byte(process) ||
		EB0 == 0 || EB1 == 0 || EB1 == INDIRECT || EB2 != REGISTER)
	{
		move_pc_by_encoding_byte(process, 1, 3);
		return ;
	}
	if (!parse_arguments(process, 1))
		return ;
	if (EB0 == REGISTER)
		a = smash_bytes(REG[ARG00]);
	else if (EB0 == DIRECT)
		a = smash_bytes(ARG0) >> 16;
	else if (EB0 == INDIRECT)
	{
		index = get_index(index, ARG00, ARG01);
		if (ARG00 >> 7)
			a = read_from_board(core->node_addresses_rev[index], 4);
		else
			a = read_from_board(core->node_addresses[index], 4);
	}
	if (EB1 == REGISTER)
		b = smash_bytes(REG[ARG10]);
	else if (EB1 == DIRECT)
		b = smash_bytes(ARG1) >> 16;
	a += b;
	if (a >> 15)
	{
		a = (~a + 1);
		a %= IDX_MOD;
		index = (MEM_SIZE - index - 1);
		location = core->node_addresses_rev[(index + a) % MEM_SIZE];
	}
	else
		location = core->node_addresses[(index + (a % IDX_MOD)) % MEM_SIZE];
	write_number_to_register(REG[ARG20], read_from_board(location, 4));
}
