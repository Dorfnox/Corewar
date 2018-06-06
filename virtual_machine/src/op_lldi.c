/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:29 by bpierce          ###   ########.fr       */
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
	uint32_t 		a;
	uint32_t 		b;
	t_board_node	*index;

	a = 0;
	b = 0;
	index = process->curr_pc;
	parse_encoding_byte(process);
	if (EB2 != REGISTER || EB0 == 0 || EB1 == 0 || EB1 == INDIRECT)
		return ;
	if (!parse_arguments(process))
		return ;
	if (EB0 == REGISTER)
		a = smash_bytes(process->reg[process->args[0][0]]);
	else if (EB0 == DIRECT)
		a = smash_bytes(process->args[0]) >> 16;
	else if (EB0 == INDIRECT)
	{
		index = core->node_addresses[(index->index + ((smash_bytes(process->args[0]) >> 16))) % MEM_SIZE];
		a = read_from_board(index, 4);
	}
	if (EB1 == REGISTER)
		b = smash_bytes(process->reg[process->args[1][0]]);
	else if (EB1 == DIRECT)
		b = smash_bytes(process->args[1]) >> 16;
	a += b;
	write_number_to_register(process->reg[process->args[2][0]], a);
	process->carry = !!smash_bytes(process->reg[process->args[2][0]]);
}
