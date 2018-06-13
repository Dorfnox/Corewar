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
	uint32_t a;
	uint32_t b;
	uint16_t index;
	t_board_node *tmp;

	tmp = process->curr_pc;
	a = 0;
	b = 0;
	if (!parse_encoding_byte(process))
		return ;
	if (EB0 != REGISTER || EB1 == 0 || EB2 == INDIRECT || EB2 == 0)
		return ;
	if (!parse_arguments(process))
		return ;
	if (EB1 == REGISTER)
		a = smash_bytes(process->reg[process->args[1][0]]);
	else if (EB1 == DIRECT)
		a = smash_bytes(process->args[1]) >> 16;
	else if (EB1 == INDIRECT)
	{
		index = get_index(tmp->index, process->args[1][0], process->args[1][1]);
		a = read_from_board(core->node_addresses[index], 4);
	}
	if (EB2 == REGISTER)
		b = smash_bytes(process->reg[process->args[2][0]]);
	else if (EB2 == DIRECT)
		b = smash_bytes(process->args[2]) >> 16;
	a += b;
	tmp = core->node_addresses[(tmp->index + (uint16_t)(a % IDX_MOD)) % MEM_SIZE];
	write_number_to_board(tmp, process->args[0]);
	VIZ(draw_to_bored(core, process->player->player_num, tmp->index, 4));
}
