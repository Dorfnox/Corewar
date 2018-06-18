/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_playa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:42:53 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/17 12:44:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    init_ncurses_playa(t_corewar *core)
{
    uint8_t     i;
    WINDOW      *win;

    i = -1;
    while (++i < MAX_PLAYERS)
    {
        if (core->player[i].player_num)
        {
            win = newwin(7, 40, (7 * i) + 7, 200);
            MALL_ERR(core->ncur.bored, "Failed to create ncurses playa");
            wattron(win, COLOR_PAIR(core->player[i].player_num));
            box(win, 0, 0);
            wrefresh(win);
            core->ncur.playa[i] = win;
        }
    }
}

void		print_process_info(t_ncurses *n, t_process *p)
{
	static WINDOW	*win;

	win = n->playa[p->player->player_num - 1];
    wattron(win, COLOR_PAIR(p->player->player_num));
	mvwprintw(win, 1, 1, "Player #:    %4u", p->player->player_num);
	mvwprintw(win, 2, 1, "Process cnt: %4u", p->player->num_of_processes);
	mvwprintw(win, 3, 1, "Process id:  %4u", p->id);
	mvwaddstr(win, 4, 1, "--------------");
	mvwprintw(win, 5, 1, "current pc: %4u, board value: %.2x",
		p->curr_pc->index, p->curr_pc->value);
	wrefresh(win);
}
