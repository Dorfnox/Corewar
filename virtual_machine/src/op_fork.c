/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:31 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0c - FORK
**	- - - - - - - - - -
**	Creates a new process for the player, and copies the current process's
**	registry into the new process
**
**	Not followed by parameter encoding byte
**
**	executes process at PC + index, with a % IDX_MOD restriction
**
*/

void		fork_(t_corewar *core, t_process *process)
{
	uint16_t		arg;
	t_board_node	*index;
	t_process		*new_p; 

	arg = (uint16_t)read_from_board(process->curr_pc->next, 2);
	index = core->node_addresses[(process->curr_pc->index + (arg % IDX_MOD)) % MEM_SIZE];
	new_p = new_process(process->player, index, process);
	insert_process(&core->process_stack[core->env.cycle % PROCESS_STACK_LEN], new_p);
	process->curr_pc = process->curr_pc->next->next->next;
//	DB("FORKINGGG!!!");
}
