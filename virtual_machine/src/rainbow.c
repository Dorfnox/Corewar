/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:10:11 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 14:19:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	COLOR_WHITE is changed for rainbow usage
**	So anything based off of COLOR_WHITE (for example, DF, or the default),
**	it's color will change.
*/

void			rainbow(t_corewar *core)
{
	init_color(COLOR_WHITE,
		RAINBOW_CYCLE((core->env.rainbow_red % RAINBOW_VALUE)),
		RAINBOW_CYCLE((core->env.rainbow_green % RAINBOW_VALUE)),
		RAINBOW_CYCLE((core->env.rainbow_blue % RAINBOW_VALUE)));
	core->env.rainbow_red += core->env.rainbow_speed;
	core->env.rainbow_green += core->env.rainbow_speed;
	core->env.rainbow_blue += core->env.rainbow_speed;
}

unsigned int	flag_rainbow(t_corewar *core, char ***argv)
{
	char		**av;

	if (core->flag.rainbow)
		corewar_error("Double Rainbows can't appear across the skyyyy!", 1);
	av = (*argv) + 1;
	core->env.rainbow_speed = 1;
	if (ft_isstrdigits(*av))
	{
		core->env.rainbow_speed = ft_atoi(*av);
		if (core->env.rainbow_speed > 10 || !core->env.rainbow_speed)
			corewar_error("Please provide a rainbow speed between 1 and 10", 1);
		*argv = av;
	}
	core->env.rainbow_red = 0;
	core->env.rainbow_green = 4000;
	core->env.rainbow_blue = 2000;
	return ((core->flag.rainbow = 1));
}
