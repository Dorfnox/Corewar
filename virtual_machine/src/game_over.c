/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:40:25 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 16:57:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		game_over(t_corewar *core)
{
	if (core->flag.viz)
	{
		print_game_info(core);
		MALL_ERR((core->ncur.winwin = newwin(10, 141, 28, 26)),
			"Failed to make new window");
		wattron(core->ncur.winwin, COLOR_PAIR(P4));
		box(core->ncur.winwin, 0, 0);
		declare_winner(core);
	}
	else
	{
		if (core->env.last_player_to_call_live)
		{
			ft_pflite("Player # %u - %s is the WINNER!\n--- \"%s\"\n",
				core->env.last_player_to_call_live,
				core->player[LAST_PLAYA].header.prog_name,
				core->player[LAST_PLAYA].header.comment);
		}
		else
			ft_pflite(RED "Losers\n" YELLOW "No one called live\n");
	}
	return (0);
}

void		declare_winner(t_corewar *core)
{
	if (core->env.last_player_to_call_live)
	{
		wattron(core->ncur.winwin, COLOR_PAIR(P1));
		mvwprintw(core->ncur.winwin, 3, 50, "Player # %u - %s is the WINNER!",
				core->env.last_player_to_call_live,
				core->player[LAST_PLAYA].header.prog_name);
		ft_str128(1, core->player[LAST_PLAYA].header.comment);
		mvwprintw(core->ncur.winwin, 5,
				65 - (ft_strlen(ft_str128(0)) / 2), "-- \"%s\"",
				ft_str128(0));
	}
	else
	{
		wattron(core->ncur.winwin, COLOR_PAIR(P3));
		mvwprintw(core->ncur.winwin, 3, 50, "Losers");
		mvwprintw(core->ncur.winwin, 4, 45, "No one called live");
	}
	mvwprintw(core->ncur.winwin, 7, 1, "Thanks for playing Corewarz with us.");
	mvwprintw(core->ncur.winwin, 8, 1, "bpierce, dmontoya, kmckee, rzarate");
	wrefresh(core->ncur.winwin);
	key_hit(core);
}
