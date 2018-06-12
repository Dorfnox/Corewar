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

t_process	*new_process(t_player *player,
	t_board_node *start_pos, t_process *cpy)
{
	t_process		*new;
	int64_t			reg_ctr;
	int64_t			byte;
	static uint64_t	id;

	MALL_ERR((new = ft_memalloc(sizeof(t_process))), "Creating new process");
	new->player = player;
	new->curr_pc = start_pos;
	new->instruct = first_;
	new->carry = cpy ? cpy->carry : 0;
	new->id = id++;
	reg_ctr = -1;
	while (++reg_ctr < REG_NUMBER + 1)
		if ((byte = -1))
			while (++byte < REG_SIZE)
				new->reg[reg_ctr][byte] = cpy ? cpy->reg[reg_ctr][byte] : 0;
	new->reg[1][0] = cpy ? cpy->reg[1][0] : 0xFF;
	new->reg[1][1] = cpy ? cpy->reg[1][1] : 0xFF;
	new->reg[1][2] = cpy ? cpy->reg[1][2] : 0xFF;
	new->reg[1][3] = cpy ? cpy->reg[1][3] : (~(player->player_num) + 1);
	return (new);
}

void		insert_process(t_corewar *core, t_stack *s, t_process *p)
{
	t_node		*head;
	t_node		*n;
	t_process	*tmp;

	if (!s->top)
		push(s, p);
	else if ((tmp = peeks(s)) && p->id > tmp->id)
		push(s, p);
	else
	{
		head = s->top;
		n = s->top;
		s->top = s->top->next;
		while ((tmp = peeks(s)))
		{
			if (p->id > tmp->id)
				break ;
			n = s->top;
			s->top = s->top->next;
		}
		push(s, p);
		n->next = s->top;
		s->top = head;
	}
	VIZ(push_process_cursor(core, p));
}

/*
**	Adds to the cursor stack for the given index location
*/

void		push_process_cursor(t_corewar *core, t_process *process)
{
	t_cursor	*cursor;

	cursor = &(core->ncur.cursor[process->curr_pc->index]);
	if (CE_2(process->instruct, fork_, lfork_))
	{
		while (!isemptys(&cursor->cursor_stack))
			pop(&cursor->cursor_stack);
	}
	push(&cursor->cursor_stack, process);
	draw_cursor(core, cursor);
}

void		pop_process_cursor(t_corewar *core, t_process *process)
{
	static t_cursor		*cursor;
	static t_node		*p;
	static t_node		*prev;

	cursor = &(core->ncur.cursor[process->curr_pc->index]);
	if (isemptys(&cursor->cursor_stack))
		return ;
	if (cursor->cursor_stack.size == 1 &&
		peeks(&cursor->cursor_stack) != process)
		return ;
	if (peeks(&cursor->cursor_stack) == process)
		pop(&cursor->cursor_stack);
	else
	{
		p = cursor->cursor_stack.top;
		while (peeks(&cursor->cursor_stack) != process)
		{
			prev = cursor->cursor_stack.top;
			cursor->cursor_stack.top = cursor->cursor_stack.top->next;
			if (cursor->cursor_stack.top == NULL)
			{
				cursor->cursor_stack.top = p;
				return ;
			}
		}
		pop(&cursor->cursor_stack);
		prev->next = cursor->cursor_stack.top;
		cursor->cursor_stack.top = p;
	}
	draw_cursor(core, cursor);
}

void		draw_cursor(t_corewar *core, t_cursor *c)
{
	t_process	*p;

	if ((p = peeks(&c->cursor_stack)))
	{
	    wattron(core->ncur.bored, COLOR_PAIR(p->player->player_num + 4));
	}
	else
	{
		wattron(core->ncur.bored, COLOR_PAIR(c->bored_color));
	}
	mvwaddstr(core->ncur.bored, c->y, c->x,
		core->ncur.c_array[core->node_addresses[c->idx]->value]);
	wrefresh(core->ncur.bored);
}
