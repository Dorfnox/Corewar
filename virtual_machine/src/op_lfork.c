/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:06:37 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0f - LONG FORK
**	- - - - - - - - - -
**	Creates a new process for the player, and copies the current process's
**	registry into the new process
**
**	Not followed by parameter encoding byte
**
**	executes process at PC + INDEX, without the % IDX_MOD restriction
*/

void		lfork_(t_corewar *core, t_process *process)
{
	uint16_t		idx;
	t_board_node	*start;
	t_process		*new_p;

	idx = get_index_unchained(process->curr_pc->index,
		process->curr_pc->next->value, process->curr_pc->next->next->value);
	if (process->curr_pc->next->value >> 7)
		start = core->node_addresses_rev[idx];
	else
		start = core->node_addresses[idx];
	new_p = new_process(core, process->player, start, process);
	new_p->op = &core->op[ZERO_AT_BAD_INSTR(start->value)];
	insert_process(core,
		&core->process_stack[(core->env.cycle + new_p->op->wait_time)
						% PROCESS_STACK_LEN], new_p);
	process->player->num_of_processes++;
	core->env.total_processes++;
	process->curr_pc = process->curr_pc->next->next->next;
}
