/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0b - STORE INDEX
**	- - - - - - - - - -
**	Stores an indexed value onto the board from a register
**
**	Takes 3 parameters (1 registry, 2 others), adds last two indexes,
**	and puts the first-parameter's register value onto the board at index_sum
**
**	REG_SIZE bytes are read from the register
*/

void		sti_(t_corewar *core, t_process *process)
{
	uint32_t		idx_result;
	uint16_t		index;
	t_board_node	*location;

	index = process->curr_pc->index;
	if (!parse_encoding_byte(process) ||
		EB0 != REGISTER || EB1 == 0 || EB2 == 0 || EB2 == INDIRECT)
	{
		move_pc_by_encoding_byte(process, 1);
		return ;
	}
	if (!parse_arguments(process, 1))
		return ;
	idx_result = sti_a_index(core, process, index) + sti_b_index(process);
	if (idx_result >> 15)
	{
		idx_result = ~idx_result + 1;
		idx_result %= IDX_MOD;
		index = (MEM_SIZE - index - 1);
		location = core->node_addresses_rev[
			(index + idx_result) % MEM_SIZE];
	}
	else
		location = core->node_addresses[
			(index + (idx_result % IDX_MOD)) % MEM_SIZE];
	write_number_to_board(location, REG[ARG00]);
	VIZ(draw_to_bored(core, process->player->player_num, location->index, 4));
}

uint32_t	sti_a_index(t_corewar *core, t_process *process, uint16_t index)
{
	uint32_t	a;

	a = 0;
	if (EB1 == REGISTER)
		a = smash_bytes(process->reg[ARG10]);
	else if (EB1 == DIRECT)
	{
		a = smash_bytes(ARG1) >> 16;
	}
	else if (EB1 == INDIRECT)
	{
		index = get_index(index, ARG10, ARG11);
		if (ARG10 >> 7)
			a = read_from_board(core->node_addresses_rev[index], 4);
		else
			a = read_from_board(core->node_addresses[index], 4);
	}
	return (a);
}

uint32_t	sti_b_index(t_process *process)
{
	uint32_t	b;

	b = 0;
	if (EB2 == REGISTER)
	{
		b = smash_bytes(REG[ARG20]);
	}
	else if (EB2 == DIRECT)
	{
		b = smash_bytes(ARG2) >> 16;
	}
	return (b);
}