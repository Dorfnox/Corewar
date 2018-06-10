/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:48:03 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/10 00:48:05 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_process_info(t_process *p)
{
	uint8_t		x;
	uint8_t		y;

	x = 200;
	y = 30 * p->player->player_num;
	mvprintw(y, x, "Player: %u\n----------\ncurr_pc: %4u, board-value: %.8x",
		p->player->player_num,
		p->curr_pc->index,
		p->curr_pc->value);
	refresh();
}
