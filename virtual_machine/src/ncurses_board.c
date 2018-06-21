/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:39:38 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:27:27 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_ncurses_bored(t_corewar *core)
{
	uint16_t	i;
    WINDOW      *border;

    border = newwin(66, (64 * 2) + 67, 0, 0);
    wattron(border, COLOR_PAIR(ORANGE_STUFF));
    box(border, 0, 0);
    wrefresh(border);
	core->ncur.bored = newwin(64, (64 * 2) + 63, 1, 2);
	MALL_ERR(core->ncur.bored, "Failed to create ncurses board");
	wattron(core->ncur.bored, COLOR_PAIR(DF));
	i = -1;
	while (++i < MEM_SIZE)
	{
		waddstr(core->ncur.bored, "00");
		if (((i + 1) % 64) != 0)
			waddch(core->ncur.bored, ' ');
	}
	wmove(core->ncur.bored, 0, 0);
	wrefresh(core->ncur.bored);
}

void	draw_to_bored(t_corewar *core, uint8_t player_num,
					uint16_t idx, uint8_t len)
{
	uint8_t		i;

	i = -1;
	while (++i < len)
	{
		core->node_addresses[idx]->bored_color = player_num;
		draw_cursor(core, core->node_addresses[idx]);
		idx = ((idx + 1) == MEM_SIZE) ? 0 : (idx + 1);
	}
}
