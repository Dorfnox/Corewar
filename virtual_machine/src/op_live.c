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
	process->curr_pc = process->curr_pc->next;
	while (++i < 4)
	{
		player_num <<= 8;
		player_num |= process->curr_pc->value;
		process->curr_pc = process->curr_pc->next;
	}
	if (player_num < 0xFFFFFFFC)
		return ;
	player_num = ~player_num;
	core->player[player_num].num_live++;
	core->player[player_num].last_live = core->env.cycle;
	core->env.last_cycle_when_live_was_called = core->env.cycle;
	core->env.last_player_to_call_live = player_num + 1;
	core->env.nbr_live -= (core->env.nbr_live == 0) ? 0 : 1;
	core->env.total_lives++;
}
