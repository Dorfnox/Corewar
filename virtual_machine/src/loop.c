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
	uint8_t     board_value;
	t_process   *p;
	while (1) // live hasn't been called within the last cycle by at least 1 champion and other stuff
	{
		while (!isemptys(&core->process_stack[core->env.cycle % PROCESS_STACK_LEN]))
		{
			p = pop(&core->process_stack[core->env.cycle % PROCESS_STACK_LEN]);
			VIZ(draw_process(&core->ncur, p));
			VIZ(print_process_info(&core->ncur, p));
			p->instruct(core, p);
			board_value = ZERO_AT_BAD_INSTR(p->curr_pc->value);
			p->instruct = core->op[board_value].instruct;
			insert_process(&core->process_stack[(core->env.cycle + core->op[board_value].wait_time) % PROCESS_STACK_LEN], p);
		}
        game_speed(8); // 1 is fast, 50 is slow
        ++core->env.cycle;
	}
}

void    game_speed(uint8_t speed)
{
    int j = 0;

    while (j++ < ((speed * PROCESS_STACK_LEN * 10) << 3))
        for (int64_t d = 0; d < speed; d++){}
}