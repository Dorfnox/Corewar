/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 17:11:53 by bpierce          ###   ########.fr       */
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
	t_board_node	*location;

	location = NULL;
	index = process->curr_pc->index;
	if (!parse_encoding_byte(core, process) ||
		EB0 != REGISTER || EB1 == 0 || EB1 == DIRECT)
	{
		return (move_pc_by_encoding_byte(core, process, 0, 2));
	}
	if (!parse_arguments(core, process, 0))
		return ;
	if (EB1 == REGISTER)
		write_reg_to_reg(REG[ARG10], REG[ARG00]);
	else if (EB1 == INDIRECT)
	{
		index = get_index(index, ARG10, ARG11);
		if (ARG10 >> 7)
			location = core->node_addresses_rev[index];
		else
			location = core->node_addresses[index];
		write_number_to_board(location, REG[ARG00]);
		VIZ(draw_to_bored(core,
					process->player->player_num, location->index, 4));
	}
}
