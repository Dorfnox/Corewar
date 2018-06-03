/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:59:00 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x01 - LIVE
**	- - - - - - - - - -
**	Calls 'live' given a valid player (4 bytes on the board)
**	Moves the process's PC after the 4 bytes for the players number
*/

void		live_(t_corewar *core, t_process *process)
{
	uint32_t	player_num;
	int			i;

	i = -1;
	player_num = 0;
	process->curr_pc = process->curr_pc->next; // Added this (moves to byte AFTER 0x01)
	// player_num |= (uint32_t)process->curr_pc->value << 24;
	// player_num |= (uint32_t)process->curr_pc->next->value << 16;
	// player_num |= (uint32_t)process->curr_pc->next->next->value << 8;
	// player_num |= (uint32_t)process->curr_pc->next->next->next->value;
	//	Then add as the last line:
	// process->curr_pc = process->curr_pc->next->next->next->next; // AMAZING LINE
	while (++i < 4)
	{
		player_num <<= 8;
		player_num |= process->curr_pc->value;
		process->curr_pc = process->curr_pc->next;
	}
	if (player_num < 0xFFFFFFFC)
		return ;
	// Do we need to minus one if we just don't do +1 in the first place?
	player_num = ~player_num + 1;
	core->player[player_num - 1].num_live++;
	core->player[player_num - 1].last_live = core->env.cycle;
}
