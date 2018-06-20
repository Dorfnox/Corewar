/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:45:23 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:24:54 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	loop(t_corewar *core)
{
	uint8_t		board_value;
	t_process	*process;

	while (1)
	{
		++core->env.cycle;
		cycle_handle(core);
		while (!isemptys(&PROCESS_STACK[CURRENT_CYCLE]))
		{
			process = pop(&PROCESS_STACK[CURRENT_CYCLE]);
			process->op->instruct(core, process);
			board_value = ZERO_AT_BAD_INSTR(process->curr_pc->value);
			process->op = &core->op[board_value];
			insert_process(core, &core->process_stack[(core->env.cycle +
				process->op->wait_time) % PROCESS_STACK_LEN], process);
		}
		game_speed(core->env.game_speed);
	}
}

void	loop_viz(t_corewar *core)
{
	uint8_t		board_value;
	t_process	*process;

	while (1)
	{
		++core->env.cycle;
		cycle_handle(core);
		while (!isemptys(&PROCESS_STACK[CURRENT_CYCLE]))
		{
			process = pop(&PROCESS_STACK[CURRENT_CYCLE]);
			pop_process_cursor(core, process);
			print_process_info(&core->ncur, process);
			process->op->instruct(core, process);
			board_value = ZERO_AT_BAD_INSTR(process->curr_pc->value);
			process->op = &core->op[board_value];
			insert_process(core, &core->process_stack[(core->env.cycle +
				process->op->wait_time) % PROCESS_STACK_LEN], process);
			wrefresh(core->ncur.playa[process->player->player_num - 1]);
		}
		print_game_info(core);
		// if (core->env.cycle > 3304)
		// 	key_hit(core);
		game_speed(core->env.game_speed);
	}
}

void	game_speed(uint8_t speed)
{
	int		j;
	int64_t	d;

	d = -1;
	j = 0;
	while (j++ < ((speed * PROCESS_STACK_LEN * 10) << 3))
		while (++d < speed)
		{
		}
}
