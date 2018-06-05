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
	if (EB0 != 1 || EB1 == 2)
		return ;
	if (!parse_arguments(process))
		return ;
	if (EB1 == 1)
	{
		write_reg_to_reg(process->reg[process->args[1][0]], process->reg[process->args[0][0]]);
		ft_printf("args00%d\n", process->args[0][0]); //debug
		ft_printf("register 2 now: %x\n", process->reg[2][0]); //debug
	}
	if (EB1 == 3)
	{
		index = get_index(index, process->args[1][0], process->args[1][1]);
		write_number_to_board(core->node_addresses[index], process->reg[process->args[0][0]]);
		print_board(core); //debugging
	}
}
