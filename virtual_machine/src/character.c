/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:14:56 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/09 19:15:03 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Initializes both the character array,
**	and the index array
*/

void	init_ncurses_arrays(t_corewar *c)
{
	uint16_t		i;
	char			*t;

	t = "0123456789ABCDEF";
	i = -1;
	while (++i < 256)
	{
		c->ncur.c_array[i][0] = t[i / 16];
		c->ncur.c_array[i][1] = t[i % 16];
	}
	i = -1;
	while (++i < MEM_SIZE)
	{
        c->ncur.cursor[i].idx = i;
		c->ncur.cursor[i].y = i / 64;
		c->ncur.cursor[i].x = (i % 64) * 3;
        c->ncur.cursor[i].bored_color = DF;
	}
}