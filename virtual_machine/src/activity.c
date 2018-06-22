/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:07:40 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 19:07:45 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			activity(t_corewar *core)
{
	t_node	*node;
	uint8_t	i;

	node = core->process_stack[(core->env.cycle + 1) % PROCESS_STACK_LEN].top;
	wmove(core->ncur.infoz, 12, 1);
	wattron(core->ncur.infoz, COLOR_PAIR(ORANGE_BAR));
	i = 0;
	while (node && ++i < 38)
	{
		waddch(core->ncur.infoz, ' ');
		node = node->next;
	}
	wattron(core->ncur.infoz, COLOR_PAIR(ORANGE_STUFF));
	mvwaddstr(core->ncur.infoz, 11, 1, "Activity | ");
	wprintw(core->ncur.infoz, "%-6u", i);
	wattron(core->ncur.infoz, COLOR_PAIR(DF_BAR));
	wmove(core->ncur.infoz, 12, i + 1);
	while (i++ < 38)
		waddch(core->ncur.infoz, ' ');
}

unsigned int	flag_activity(t_corewar *core, char ***argv)
{
	(void)argv;
	if (core->flag.activity)
		corewar_error("Please don't use the '-a' flag more than once", 1);
	return ((core->flag.activity = 1));
}
