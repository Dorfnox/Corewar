/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_infoz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:48:03 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/17 12:44:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    init_ncurses_infoz(t_corewar *core)
{
    uint16_t    width;
    uint16_t    height;
    uint16_t    i;
    uint16_t    j;

    width = 40;
    height = 6;
    core->ncur.infoz = newwin(height, width, 0, 200);
    MALL_ERR(core->ncur.infoz, "Failed to create ncurses infoz");
    wattron(core->ncur.infoz, COLOR_PAIR(INFOZ));
    wmove(core->ncur.infoz, 0, 0);
    i = 0;
    while (i++ < height)
    {
        j = 0;
        while (j++ < width)
            waddch(core->ncur.infoz, ' ');
    }
    wclear(core->ncur.infoz);
    box(core->ncur.infoz, 0, 0);
    mvwprintw(core->ncur.infoz, 1, 1, "Information");
    wrefresh(core->ncur.infoz);
}

void		print_game_info(t_corewar *core)
{
	mvwprintw(core->ncur.infoz, 2, 1, "Cycle: %u", core->env.cycle);
	mvwprintw(core->ncur.infoz, 3, 1, "Cycle To Die: %u", core->env.cycle);
	wrefresh(core->ncur.infoz);
}
