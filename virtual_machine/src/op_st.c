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

	index = process->curr_pc->index;
	parse_encoding_byte(process);
	if (EB0 != REGISTER || EB1 == DIRECT)
		return ;
	if (!parse_arguments(process))
		return ;
	if (EB1 == REGISTER)
		write_reg_to_reg(REG[ARG10], REG[ARG00]);
	if (EB1 == INDIRECT)
	{
		index = get_index(index, ARG10, ARG11);
		// mvwprintw(core->ncur.infoz, 0, 0, "b1: %.2X, b2: %.2X", ARG10, ARG11);
		// wrefresh(core->ncur.infoz);
		write_number_to_board(core->node_addresses[index], REG[ARG00]);
		VIZ(draw_to_bored(core, process->player->player_num, index, 4));
	}
}
