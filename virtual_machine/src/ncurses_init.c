/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:18:43 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:42:16 by dmontoya         ###   ########.fr       */
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
	init_ncurses_character_array(core);
	init_ncurses_bored(core);
	init_ncurses_playa(core);
	init_ncurses_infoz(core);
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
}

void	init_ncurses_colors(void)
{
	init_color(COLOR_BLUE, 215, 1000, 1000);
	init_pair(P1, COLOR_GREEN, COLOR_BLACK);
	init_pair(P2, COLOR_BLUE, COLOR_BLACK);
	init_pair(P3, COLOR_RED, COLOR_BLACK);
	init_pair(P4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P1B, COLOR_BLACK, COLOR_GREEN);
	init_pair(P2B, COLOR_BLACK, COLOR_BLUE);
	init_pair(P3B, COLOR_BLACK, COLOR_RED);
	init_pair(P4B, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(DF, COLOR_WHITE, COLOR_BLACK);
	init_pair(INFOZ, COLOR_BLACK, COLOR_GREEN);
}

void	init_ncurses_character_array(t_corewar *c)
{
	uint16_t	i;
	char		*t;

	t = "0123456789ABCDEF";
	i = -1;
	while (++i < 256)
	{
		c->ncur.c_array[i][0] = t[i / 16];
		c->ncur.c_array[i][1] = t[i % 16];
	}
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
