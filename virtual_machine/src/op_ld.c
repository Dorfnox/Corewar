/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x02 - LOAD
**	- - - - - - - - - -
**	Loads a value into a register, with a % IDX_MOD restriction
**
**	2 Parameters: 2nd must be a register (NOT THE PC)
*/

void		ld_(t_corewar *core, t_process *process)
{
	uint16_t		index;

	index = process->curr_pc->index;
	parse_encoding_byte(process);
	if ((EB0 < 2 || EB1 != 1 || EB2) && !(process->carry = 0))
		return;
	parse_arguments(process);
	if ((process->args[1][0] > 16 || process->args[1][0] < 1) && !(process->carry = 0))
		return;
	if (EB0 == DIRECT && (process->carry = 1))
		ft_memcpy(process->reg[process->args[1][0]], process->args[0], 4);
	else if (EB0 == INDIRECT && (process->carry = 1))
	{
		index = get_index(index, process->args[0][0], process->args[0][1]);
		write_board_to_register(process->reg[process->args[1][0]], core->node_addresses[index]);
	}
	else
		process->carry = 0;
	printf("register 2 is now: %d\n", process->reg[2][0]); //debug
}
