/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:34:28 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:46:28 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates a new process given the player that 'owns' the process, and the
**	'Start location' on the board.
**	If given a previous process, will copy the register over as well.
*/

t_process	*new_process(t_player *player, t_board_node *start_pos, t_process *to_copy)
{
	t_process		*new;
	int64_t			reg_ctr;
	int64_t			byte;
	static uint64_t	process_num;

	if (!player)
		corewar_error("Failed to attach a player to the new process", 1);
	if (!(new = ft_memalloc(sizeof(t_process))))
		corewar_error("Unable to malloc a process: Reached max heapness!!", 1);
	new->player = player;
	new->curr_pc = start_pos;
	new->instr = first_;
	new->process_num = process_num++;
	reg_ctr = -1;
	while (++reg_ctr < REG_NUMBER + 1)
	{
		byte = -1;
		while (++byte < REG_SIZE)
			new->reg[reg_ctr][byte] = to_copy ? to_copy->reg[reg_ctr][byte] : 0;
	}
	new->reg[1][0] = to_copy ? to_copy->reg[1][0] : 0xFF;
	new->reg[1][1] = to_copy ? to_copy->reg[1][1] : 0xFF;
	new->reg[1][2] = to_copy ? to_copy->reg[1][2] : 0xFF;
	new->reg[1][3] = to_copy ? to_copy->reg[1][3] : (~(player->player_num) + 1);
	return (new);
}
