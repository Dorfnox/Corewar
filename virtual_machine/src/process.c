/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:34:28 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:46:28 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates a new process given the player that 'owns' the process, and the
**	'Start location' on the board.
**	If given a previous process, will copy the register over as well.
*/

t_process	*new_process(t_player *player, t_board_node *start_pos, t_process *to_copy)
{
	t_process		*new;
	int64_t			reg_ctr;
	int64_t			byte;
	static uint64_t	process_num;

	if (!player)
		corewar_error("Failed to attach a player to the new process", 1);
	if (!(new = ft_memalloc(sizeof(t_process))))
		corewar_error("Unable to malloc a process: Reached max heapness!!", 1);
//	DB("ahfdsf");		
	new->player = player;
	new->curr_pc = start_pos;
	new->instruct = first_;
	new->carry = to_copy ? to_copy->carry : 0;
	new->process_num = process_num++;
	reg_ctr = -1;
	while (++reg_ctr < REG_NUMBER + 1)
	{
		byte = -1;
		while (++byte < REG_SIZE)
			new->reg[reg_ctr][byte] = to_copy ? to_copy->reg[reg_ctr][byte] : 0;
	}
	new->reg[1][0] = to_copy ? to_copy->reg[1][0] : 0xFF;
	new->reg[1][1] = to_copy ? to_copy->reg[1][1] : 0xFF;
	new->reg[1][2] = to_copy ? to_copy->reg[1][2] : 0xFF;
	new->reg[1][3] = to_copy ? to_copy->reg[1][3] : (~(player->player_num) + 1);
//	ft_pflite("-----\nPlayer: %s\nCurrent PC: %u\nProcess ID: %u\n-----\n", player->header.prog_name, new->curr_pc->index, new->process_num);
	return (new);
}

void		insert_process(t_stack *s, t_process *p)
{
	t_node		*head;
	t_node		*n;
	t_process	*tmp;

	if (!s->top)
		push(s, p);
	else if ((tmp = peeks(s)) && p->process_num > tmp->process_num)
		push(s, p);
	else
	{
		head = s->top;
		n = s->top;
		s->top = s->top->next;
		while ((tmp = peeks(s)))
		{
			if (p->process_num > tmp->process_num)
				break ;
			n = s->top;
			s->top = s->top->next;
		}
		push(s, p);
		n->next = s->top;
		s->top = head;
	}
}
