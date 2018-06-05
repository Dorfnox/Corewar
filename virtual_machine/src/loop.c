/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:45:23 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:28:58 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    loop(t_corewar *core)
{
	uint64_t    i;
	uint8_t     board_value;
	t_process   *p;

	i = 0;
	while (1) // live hasn't been called within the last cycle by at least 1 champion and other stuff
	{
        DBI(i);
        if (i > 100)
        	break ;
		while (!isemptys(&core->process_stack[i % 1000]))
		{
			p = pop(&core->process_stack[i % 1000]);
			p->instr(core, p);
			// --------------------
            // --------------------
			board_value = ZERO_AT_BAD_INSTR(p->curr_pc->value);
			p->instr = core->op[board_value].instr;
			insert_process(&core->process_stack[(i + core->op[board_value].wait_time) % 1000], p);
			// push(&core->process_stack[(i + core->op[board_value].wait_time) % 1000], p);
		}
        game_speed(15); // 1 is fast, 50 is slow
        ++i;
	}
}

void    game_speed(uint8_t speed)
{
    int j = 0;

    while (j++ < ((speed * 10000) << 3))
        for (int64_t d = 0; d < speed; d++){}
}