/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:34:28 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/31 16:09:48 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates a new process given the player that 'owns' the process, and the
**	'Start location' on the board.
*/

t_process	*new_process(t_player *player, uint32_t start_location)
{
	t_process	*new;

	if (!player)
		corewar_error("Failed to attach a player to the new process", 1);
	if (!(new = ft_memalloc(sizeof(t_process))))
		corewar_error("Unable to malloc a process: Reached max heapness!!", 1);
	new->player = player;
	ft_memcpy(&new->reg[0], &start_location, 4); // FIX!! Need a way of setting the PC.
	return (new);
}