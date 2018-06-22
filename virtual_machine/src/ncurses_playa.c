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
	uint8_t			i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (core->player[i].player_num)
		{
			core->ncur.playa[i] = newwin(6, 40, ((6 + 3) * i) + 17, 200);
			MALL_ERR(core->ncur.playa[i], "Malloc of playa");
			create_playa_window(core->ncur.playa[i], &core->player[i]);
		}
	}
}

void		create_playa_window(WINDOW *win, t_player *p)
{
	char	c;

	c = p->header.prog_name[0];
	wattron(win, COLOR_PAIR(p->player_num + 4));
	mvwprintw(win, 1, 1, "Player %d ", p->player_num);
	wattron(win, COLOR_PAIR(p->player_num));
	wattron(win, A_UNDERLINE);
	mvwprintw(win, 1, 10, " %s", p->header.prog_name);
	wattroff(win, A_UNDERLINE);
	wattron(win, COLOR_PAIR(p->player_num + 4));
	mvwaddstr(win, 3, 1, "Last Live");
	mvwaddstr(win, 4, 1, "Processes");
	wattron(win, COLOR_PAIR(p->player_num));
	wborder(win, ' ', ' ', '~', '~', c, c, c, c);
	wrefresh(win);
}

void		print_player_info(t_ncurses *n, t_process *p)
{
	wattron(n->playa[p->player->player_num - 1],
		COLOR_PAIR(p->player->player_num));
	mvwprintw(n->playa[p->player->player_num - 1],
		3, 11, "| %-8u", p->player->last_live);
	mvwprintw(n->playa[p->player->player_num - 1],
		4, 11, "| %-8u", p->player->num_of_processes);
	wrefresh(n->playa[p->player->player_num - 1]);
}
