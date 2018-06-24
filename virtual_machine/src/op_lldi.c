/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:29:34 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0e - LONG LOAD INDEX
**	- - - - - - - - - -
**	Loads an indexed value into a register, WITHOUT the % IDX_MOD restriction
**
**	Takes 3 parameters (2 indexes, 1 registry), adds first two, and puts result
**	into the third-parameter's register
**
**	REG_SIZE bytes are read at the sum of the first two indexes, then loaded
**	into whatever register is in the third parameter
**
**	NOTE: MODIFIES THE CARRY
*/

void		lldi_(t_corewar *core, t_process *process)
{
	uint16_t		index;
	uint32_t		idx_result;

	index = process->curr_pc->index;
	if (!parse_encoding_byte(core, process) ||
			EB0 == 0 || EB1 == 0 || EB1 == INDIRECT || EB2 != REGISTER)
	{
		move_pc_by_encoding_byte(core, process, 1, 3);
		return ;
	}
	if (!parse_arguments(core, process, 1))
		return ;
	idx_result = lldi_a_index(core, process, index) +
		lldi_b_index(core, process);
	do_lldi(core, process, idx_result, index);
}

uint32_t	lldi_a_index(t_corewar *core, t_process *process, uint16_t index)
{
	uint32_t	a;

	a = 0;
	if (EB0 == REGISTER)
		a = smash_bytes(REG[ARG00]);
	else if (EB0 == DIRECT)
		a = smash_bytes(ARG0) >> 16;
	else if (EB0 == INDIRECT)
	{
		index = get_index_unchained(index, ARG00, ARG01);
		if (ARG00 >> 7)
			a = read_from_board(core->node_addresses_rev[index], 4);
		else
			a = read_from_board(core->node_addresses[index], 4);
	}
	return (a);
}

uint32_t	lldi_b_index(t_corewar *core, t_process *process)
{
	uint32_t	b;

	b = 0;
	if (EB1 == REGISTER)
		b = smash_bytes(REG[ARG10]);
	else if (EB1 == DIRECT)
		b = smash_bytes(ARG1) >> 16;
	return (b);
}

void		do_lldi(t_corewar *core, t_process *process,
	uint32_t idx_result, uint16_t index)
{
	t_board_node	*location;

	if ((idx_result >> 15) & 0b1)
	{
		idx_result = (~idx_result + 1);
		index = (MEM_SIZE - index - 1);
		location = core->node_addresses_rev[(index + idx_result) % MEM_SIZE];
	}
	else
		location = core->node_addresses[(index + idx_result) % MEM_SIZE];
	write_number_to_register(REG[ARG20], read_from_board(location, 4));
	process->carry = !smash_bytes(REG[ARG20]);
}
