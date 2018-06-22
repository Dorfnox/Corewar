/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_infoz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:48:03 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:27:36 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_ncurses_infoz(t_corewar *core)
{
	uint16_t	width;
	uint16_t	height;

	width = 40;
	height = 14;
	core->ncur.infoz = newwin(height, width, 0, 200);
	MALL_ERR(core->ncur.infoz, "Failed to create ncurses infoz");
	wattron(core->ncur.infoz, COLOR_PAIR(ORANGE_STUFF));
	box(core->ncur.infoz, 0, 0);
	mvwprintw(core->ncur.infoz, 1, 1, "        -- Game Information --");
	wattron(core->ncur.infoz, COLOR_PAIR(INFOZ));
	mvwaddstr(core->ncur.infoz, 3, 1, "Current Cycle  ");
	mvwaddstr(core->ncur.infoz, 5, 1, "Round Countdown");
	mvwaddstr(core->ncur.infoz, 6, 1, "Cycles to Die  ");
	mvwaddstr(core->ncur.infoz, 7, 1, "Cycle Delta    ");
	mvwaddstr(core->ncur.infoz, 9, 1, "# of Processes ");
	wrefresh(core->ncur.infoz);
}

void		print_game_info(t_corewar *core)
{
	wattron(core->ncur.infoz, COLOR_PAIR(ORANGE_STUFF));
	mvwprintw(core->ncur.infoz, 3, 17, "| %-8u", core->env.cycle);
	mvwprintw(core->ncur.infoz, 5, 17, "| %-8u", core->env.cycle_counter);
	mvwprintw(core->ncur.infoz, 6, 17, "| %-8u", core->env.cycle_to_die);
	mvwprintw(core->ncur.infoz, 7, 17, "| %-8u", core->env.cycle_delta);
	mvwprintw(core->ncur.infoz, 9, 17, "| %-8u", core->env.total_processes);
	core->flag.activity ? activity(core) : 0;
	core->flag.rainbow ? rainbow(core) : 0;
	wrefresh(core->ncur.infoz);
}
