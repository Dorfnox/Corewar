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
	if (!parse_encoding_byte(process))
		return ;
	if (EB0 != REGISTER || EB1 == DIRECT)
		return ;
	if (!parse_arguments(process, 0))
		return ;
	if (EB1 == REGISTER)
		write_reg_to_reg(REG[ARG10], REG[ARG00]);
	if (EB1 == INDIRECT)
	{
		index = get_index(index, ARG10, ARG11);
		write_number_to_board(core->node_addresses[index], REG[ARG00]);
		VIZ(draw_to_bored(core, process->player->player_num, index, 4));
	}
}
