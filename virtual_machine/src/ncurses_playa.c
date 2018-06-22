/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_playa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:42:53 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 17:00:36 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_ncurses_playa(t_corewar *core)
{
	uint8_t		i;
	uint8_t		win_size;

	win_size = 7;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (core->player[i].player_num)
		{
			core->ncur.playa[i] = newwin(win_size, 40,
				((win_size + 3) * i) + 17, 200);
			MALL_ERR(core->ncur.playa[i], "Malloc of playa");
			wattron(core->ncur.playa[i],
				COLOR_PAIR(core->player[i].player_num));
			box(core->ncur.playa[i], 0, 0);
			wrefresh(core->ncur.playa[i]);
		}
	}
}

void		print_player_info(t_ncurses *n, t_process *p)
{
	static WINDOW	*win;

	win = n->playa[p->player->player_num - 1];
	wattron(win, COLOR_PAIR(p->player->player_num));
	mvwprintw(win, 1, 1, "Player #:    %4u", p->player->player_num);
	mvwprintw(win, 2, 1, "Process cnt: %4u", p->player->num_of_processes);
	mvwprintw(win, 3, 1, "Process id:  %4u", p->id);
	mvwaddstr(win, 4, 1, "--------------");
	mvwprintw(win, 5, 1, "Last Live:   %8u", p->player->last_live);
	wrefresh(win);
}
