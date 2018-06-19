/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:43 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x03 - STORE
**	- - - - - - - - - -
**	Stores a value onto the board from a register
*/

void		st_(t_corewar *core, t_process *process)
{
	uint16_t		index;
	uint32_t		idx_result;
	t_board_node	*location;

	location = NULL;
	index = process->curr_pc->index;
	if (!parse_encoding_byte(process) ||
		EB0 != REGISTER || EB1 == 0 || EB1 == DIRECT)
	{
		move_pc_by_encoding_byte(process, 0, 2);
		return ;
	}
	if (!parse_arguments(process, 0))
		return ;
	if (EB1 == REGISTER)
	{
		idx_result = smash_bytes(REG[ARG10]);
		// write_reg_to_reg(REG[ARG10], REG[ARG00]);
		if (idx_result & 0x8000)
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
	}
	else if (EB1 == INDIRECT)
	{
		index = get_index(index, ARG10, ARG11);
		if (ARG10 >> 7)
			location = core->node_addresses_rev[index];
		else
			location = core->node_addresses[index];
	}
	write_number_to_board(location, REG[ARG00]);
	VIZ(draw_to_bored(core, process->player->player_num, location->index, 4));
}
