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

    width = 60;
    height = 40;
    core->ncur.infoz = newwin(height, width, 22, 200);
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
	t_node	*node;
	t_process *p;
	uint8_t	i;

	mvwprintw(core->ncur.infoz, 2, 1, "Cycle: %u", core->env.cycle);
	if (core->env.cycle > 7410)
	{
		node = core->process_stack[(core->env.cycle + 1) % PROCESS_STACK_LEN].top;
		i = 3;
		while (node)
		{
			p = node->content;
			mvwprintw(core->ncur.infoz, i++, 1, "pl: %u, id: %3u, inst: %2u, x:%3u, y:%2u",
				p->player->player_num,
				p->id,
				p->curr_pc->value,
				p->curr_pc->x,
				p->curr_pc->y);
			node = node->next;
		}
		mvwprintw(core->ncur.infoz, i++, 1, "-----------------------------------");
	}
	wrefresh(core->ncur.infoz);
}
