/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:51:21 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 02:19:25 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		cycle_handle(t_corewar *core)
{
	++core->env.cycle;
	if (core->flag.dump && core->env.dump == core->env.cycle)
	{
		if (!core->flag.viz)
			dump_board((t_board_node *)core->node_addresses);
		return (game_over(core));
	}
	if (--core->env.cycle_counter == 0)
	{
		if (terminate_players(core))
			return (game_over(core));
		--core->env.max_checks;
		if (core->env.nbr_live == 0 || core->env.max_checks == 0)
		{
			if (core->env.cycle_to_die <= core->env.cycle_delta)
				return (game_over(core));
			core->env.cycle_to_die -= core->env.cycle_delta;
			core->env.max_checks = MAX_CHECKS;
		}
		core->env.nbr_live = NBR_LIVE;
		core->env.cycle_counter = core->env.cycle_to_die;
	}
	return (1);
}

uint8_t		terminate_players(t_corewar *core)
{
	uint32_t	last;
	uint8_t		i;
	uint8_t		gameisover;

	gameisover = 1;
	last = core->env.cycle - core->env.cycle_to_die;
	terminate_processes(core, core->process_stack, last);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (core->player[i].player_num)
		{
			if (!core->player[i].dead && core->player[i].num_of_processes == 0)
			{
				VIZ(wattron(core->ncur.playa[i], COLOR_PAIR(P3)));
				VIZ(mvwaddstr(core->ncur.playa[i], 1, 20, "DEAD"));
				VIZ(wattron(core->ncur.playa[i], COLOR_PAIR(i + 1)));
				VIZ(wrefresh(core->ncur.playa[i]));
				core->player[i].dead = 1;
			}
			gameisover = !core->player[i].dead ? 0 : gameisover;
		}
	}
	return (gameisover);
}

/*
**	Goes through the entire stack array and frees all processes belonging to
**	a player number.
*/

void		terminate_processes(t_corewar *core, t_stack *stk, uint32_t last)
{
	t_node		*head;
	t_node		*prev;
	t_process	*tmp;
	uint16_t	i;

	i = -1;
	while (++i < PROCESS_STACK_LEN)
	{
		head = NULL;
		prev = NULL;
		while ((tmp = peeks(&stk[i])))
		{
			while (tmp && (!tmp->last_live || tmp->last_live < last))
			{
				terminate_process(core, &stk[i]);
				tmp = peeks(&stk[i]);
			}
			head = !head ? stk[i].top : head;
			prev ? (prev->next = stk[i].top) : 0;
			if ((prev = stk[i].top))
				stk[i].top = stk[i].top->next;
		}
		stk[i].top = head;
	}
}

void		terminate_process(t_corewar *core, t_stack *stk)
{
	t_process	*tmp;

	tmp = pop(stk);
	tmp->player->num_of_processes--;
	VIZ(pop_process_cursor(core, tmp));
	free(tmp);
}

uint8_t		game_over(t_corewar *core)
{
	WINDOW		*winn;

	if (core->flag.viz)
	{
		print_game_info(core);
		MALL_ERR((winn = newwin(10, 141, 28, 26)), "Failed to make new win");
		wattron(winn, COLOR_PAIR(P4B));
		box(winn, 0, 0);
		if (core->env.last_player_to_call_live)
		{
			wattron(winn, COLOR_PAIR(P1));
			mvwprintw(winn, 3, 50, "Player # %u - %s is the WINNER!", core->env.last_player_to_call_live, 
					core->player[core->env.last_player_to_call_live - 1].header.prog_name);
			ft_str128(1, core->player[core->env.last_player_to_call_live - 1].header.comment);
			mvwprintw(winn, 5, 65 - (ft_strlen(ft_str128(0)) / 2), "-- \"%s\"", ft_str128(0));
		}
		else
		{
			wattron(winn, COLOR_PAIR(P3));
			mvwprintw(winn, 3, 50, "Losers");
			mvwprintw(winn, 4, 50, "No one called live");
		}
		mvwprintw(winn, 7, 1, "Thanks for playing Corewarz with us.");
		mvwprintw(winn, 8, 1, "bpierce, dmontoya, kmckee, rzarate");
		wrefresh(winn);
		key_hit(core);
	}
	else
	{
		if (core->env.last_player_to_call_live)
			ft_pflite("Player # %u - %s is the WINNER!\n--- \"%s\"\n", core->env.last_player_to_call_live, 
					core->player[core->env.last_player_to_call_live - 1].header.prog_name,
					core->player[core->env.last_player_to_call_live - 1].header.comment);
		else
			ft_pflite(RED "Losers\n" YELLOW "No one called live\n");
	}
	return (0);
}
