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
	static WINDOW *win;

	win = n->playa[p->player->player_num - 1];
    wattron(win, COLOR_PAIR(p->player->player_num));
	mvwprintw(win, 1, 1, "Player #:    %4u", p->player->player_num);
	mvwprintw(win, 2, 1, "Process cnt: %4u", p->player->num_of_processes);
	mvwprintw(win, 3, 1, "Process id:  %4u", p->process_num);
	mvwaddstr(win, 4, 1, "--------------");
	mvwprintw(win, 5, 1, "current pc: %4u, board value: %.2x",
		p->curr_pc->index, p->curr_pc->value);
	wrefresh(win);
}

void		print_game_info(t_corewar *core)
{
	static WINDOW *win;

	win = core->ncur.infoz;
	mvwprintw(win, 2, 1, "Cycle: %u", core->env.cycle);
	mvwprintw(win, 3, 1, "Cycle To Die: %u", core->env.cycle);
	wrefresh(win);
}