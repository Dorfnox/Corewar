/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:09:44 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/13 13:09:54 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_environment(t_corewar *core)
{
	core->env.cycle = 0;
	core->env.game_speed = GAME_SPEED;
	core->env.cycle_to_die = CYCLE_TO_DIE;
	core->env.cycle_counter = CYCLE_TO_DIE;
	core->env.cycle_delta = CYCLE_DELTA;
	core->env.nbr_live = NBR_LIVE;
	core->env.max_checks = MAX_CHECKS;
}

// uint64_t		get_max_cycles(uint64_t init)
// {
// 	if (init <= CYCLE_DELTA)
// 		return (0);
// 	return (init + get_max_cycles(init - CYCLE_DELTA));
// }
