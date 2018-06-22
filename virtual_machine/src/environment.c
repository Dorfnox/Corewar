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
	core->env.cycle = -1;
	core->env.game_speed = GAME_SPEED;
	core->env.cycle_to_die = CYCLE_TO_DIE;
	core->env.cycle_counter = CYCLE_TO_DIE + 1;
	core->env.cycle_delta = CYCLE_DELTA;
	core->env.nbr_live = NBR_LIVE;
	core->env.max_checks = MAX_CHECKS;
	init_character_array(core);
}

void		init_character_array(t_corewar *c)
{
	uint16_t	i;
	char		*t;

	t = "0123456789abcdef";
	i = -1;
	while (++i < 256)
	{
		c->env.c_array[i][0] = t[i / 16];
		c->env.c_array[i][1] = t[i % 16];
	}
}

void		init_parse_args(t_corewar *core)
{
	core->parse_arg[0] = parse_nothing;
	core->parse_arg[REGISTER] = parse_register;
	core->parse_arg[DIRECT] = parse_direct;
	core->parse_arg[INDIRECT] = parse_indirect;
}
