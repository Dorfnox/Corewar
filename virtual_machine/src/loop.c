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
		while (!isemptys(&core->process_stack[i % 1000]))
		{
			p = pop(&core->process_stack[i % 1000]);
			if (p->instr)
				p->instr(core, p);
			// --------------------
			board_value = p->curr_pc->value;
			// if (board_value < 1 || board_value > 16)
			if (board_value == 1)
			{
				p->instr = core->op[board_value].instr;
				push(&core->process_stack[(i + core->op[board_value].wait_time) % 1000], p);
				DB("WE LIVE BOIZ");
			}
			else
			{
				p->instr = NULL;
				p->curr_pc = p->curr_pc->next;
				push(&core->process_stack[(i + 1) % 1000], p);
			}
			int j = 0;
			while (j++ < 50000 << 3)
				for (int64_t d = 0; d < 20; d++){}
		}
		DBI(i++);
	}
}
