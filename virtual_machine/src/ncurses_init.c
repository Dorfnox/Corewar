/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:18:43 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 16:35:24 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**  Initializes Ncurses and draws initial screens
*/

void	init_ncurses(t_corewar *core)
{
	if (!core->flag.viz)
		return ;
	initscr();
	noecho();
	cbreak();
	start_color();
	init_ncurses_colors();
	init_ncurses_bored(core);
	init_ncurses_playa(core);
	init_ncurses_infoz(core);
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
}

/*
**  ONLY 8 colors can appear at once, but many different color_pairs
**
**  COLOR_BLACK
**  COLOR_RED
**  COLOR_GREEN
**  COLOR_YELLOW
**  COLOR_BLUE
**  COLOR_MAGENTA
**  COLOR_CYAN
**  COLOR_WHITE
*/

void	init_ncurses_colors(void)
{
	init_color(COLOR_BLUE, 215, 800, 1000);
	init_color(COLOR_WHITE, 200, 200, 200);
	init_color(COLOR_YELLOW, 855, 530, 36);
	init_pair(P1, COLOR_GREEN, COLOR_BLACK);
	init_pair(P2, COLOR_BLUE, COLOR_BLACK);
	init_pair(P3, COLOR_RED, COLOR_BLACK);
	init_pair(P4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P1B, COLOR_BLACK, COLOR_GREEN);
	init_pair(P2B, COLOR_BLACK, COLOR_BLUE);
	init_pair(P3B, COLOR_BLACK, COLOR_RED);
	init_pair(P4B, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(DF, COLOR_WHITE, COLOR_BLACK);
	init_pair(DF_BAR, COLOR_WHITE, COLOR_WHITE);
	init_pair(INFOZ, COLOR_BLACK, COLOR_YELLOW);
	init_pair(ORANGE_STUFF, COLOR_YELLOW, COLOR_BLACK);
	init_pair(ORANGE_BAR, COLOR_YELLOW, COLOR_YELLOW);
}

int		key_hit(t_corewar *core)
{
	int			ch;

	if ((ch = wgetch(core->ncur.infoz)) == ERR)
	{
		return (1);
	}
	else if (ch == ' ')
	{
		while ((ch = wgetch(core->ncur.infoz)) != ' ')
			;
	}
	return (1);
}

void	terminate_ncurses(t_corewar *core)
{
	if (core->flag.viz)
		endwin();
}
