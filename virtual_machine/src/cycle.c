/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:51:21 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 16:40:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		cycle_handle(t_corewar *core)
{
	++core->env.cycle;
	if (core->flag.dump && core->env.dump == core->env.cycle)
		return (game_over(core));
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
				VIZ(mvwaddstr(core->ncur.playa[i], 0, 18, "DEAD"));
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
**	Goes through the entire stack array and frees all processes that need to die
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
	core->env.total_processes--;
	VIZ(pop_process_cursor(core, tmp));
	free(tmp);
}
