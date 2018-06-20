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
	if (core->flag.dump && core->env.dump == core->env.cycle)
	{
		if (!core->flag.viz)
			dump_board((t_board_node *)core->node_addresses);
		game_over(core);
	}
	if (--core->env.cycle_counter == 0)
	{
		terminate_players(core);
		--core->env.max_checks;
		if (core->env.nbr_live == 0 || core->env.max_checks == 0)
		{
			if (core->env.cycle_to_die <= core->env.cycle_delta)
				game_over(core);
			core->env.cycle_to_die -= core->env.cycle_delta;
			core->env.max_checks = MAX_CHECKS;
		}
		core->env.nbr_live = 21;
		core->env.cycle_counter = core->env.cycle_to_die;
	}
	return (1);
}

void		terminate_players(t_corewar *core)
{
	uint8_t		i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (core->player[i].player_num && !core->player[i].dead)
		{
			if (core->player[i].last_live <
				(core->env.cycle - core->env.cycle_to_die))
			{
				core->player[i].dead = 1;
				terminate_player_processes(core->process_stack,
					core->player[i].player_num, -1);
			}
		}
	}
}

/*
**	Goes through the entire stack array and frees all processes belonging to
**	a player number.
*/

void		terminate_player_processes(t_stack *stk, uint8_t pnum, uint16_t i)
{
	t_node		*head;
	t_node		*prev;
	t_process	*tmp;
	t_stack		*stk2;

	while (++i < PROCESS_STACK_LEN)
	{
		if (!(stk2 = &stk[i]) || !stk2->top)
			continue ;
		head = NULL;
		prev = NULL;
		while ((tmp = peeks(stk2)))
		{
			while (tmp && tmp->player->player_num == pnum)
			{
				--tmp->player->num_of_processes;
				free(pop(stk2));
				tmp = peeks(stk2);
			}
			head = !head ? stk2->top : head;
			prev ? (prev->next = stk2->top) : 0;
			if ((prev = stk2->top))
				stk2->top = stk2->top->next;
		}
		stk[i].top = head;
	}
}

void		game_over(t_corewar *core)
{
	(void)core;
}
