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

void		print_process_info(t_ncurses *n, t_process *p)
{
    wattron(n->playa[p->player->player_num - 1],
    	COLOR_PAIR(p->player->player_num));
	mvwprintw(n->playa[p->player->player_num - 1], 0, 0,
		"Player: %u\n----------\ncurr_pc: %4u\nboard-value: %.2x",
		p->player->player_num,
		p->curr_pc->index,
		p->curr_pc->value);
	wrefresh(n->playa[p->player->player_num - 1]);
}
