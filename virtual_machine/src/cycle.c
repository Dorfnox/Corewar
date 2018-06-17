/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:51:21 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/13 13:51:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t		cycle_handle(t_corewar *core)
{
	++core->env.cycle;
	if ((core->env.cycle % core->env.max_cycles) == 0)
	{
		terminate_players(core);
		if (core->env.nbr_live == 0 || core->env.max_checks == 0)
		{
			if (core->env.cycle_to_die <= core->env.cycle_delta)
				game_over(core);
			core->env.cycle_to_die -= core->env.cycle_delta;
			core->env.max_checks = MAX_CHECKS;
		}
		core->env.nbr_live = 21;
	}
	return (1);
}

void		terminate_players(t_corewar *core)
{
	(void)core;
}

void		game_over(t_corewar *core)
{
	(void)core;
}

