/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:34:28 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:24:58 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates a new process given the player that 'owns' the process, and the
**	'Start location' on the board.
**	If given a previous process, will copy the register over as well.
*/

t_process	*new_process(t_corewar *core,
	t_player *player, t_board_node *start, t_process *cpy)
{
	t_process		*new;
	int64_t			reg_ctr;
	int64_t			byte;
	static uint64_t	id;

	MALL_ERR((new = ft_memalloc(sizeof(t_process))), "Creating new process");
	new->player = player;
	new->curr_pc = start;
	new->op = &core->op[17];
	new->carry = cpy ? cpy->carry : 0;
	new->id = id++;
	new->last_live = cpy ? cpy->last_live : 0;
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
	push(&process->curr_pc->cursor_stack, process);
	draw_cursor(core, process->curr_pc);
}

void		pop_process_cursor(t_corewar *core, t_process *process)
{
	t_board_node		*b;
	t_process			*p;
	t_node				*head;
	t_node				*prev;

	if (isemptys(&process->curr_pc->cursor_stack) || !(b = process->curr_pc))
		return ;
	if ((p = peeks(&b->cursor_stack)) == process)
	{
		pop(&b->cursor_stack);
		return (draw_cursor(core, b));
	}
	head = b->cursor_stack.top;
	while ((p = peeks(&b->cursor_stack)) != process)
	{
		prev = b->cursor_stack.top;
		b->cursor_stack.top = b->cursor_stack.top->next;
		if (b->cursor_stack.top == NULL && (b->cursor_stack.top = head))
			return ;
	}
	pop(&b->cursor_stack);
	prev->next = b->cursor_stack.top;
	b->cursor_stack.top = head;
}

void		draw_cursor(t_corewar *core, t_board_node *b)
{
	t_process		*p;

	if ((p = peeks(&b->cursor_stack)))
		wattron(core->ncur.bored, COLOR_PAIR(p->player->player_num + 4));
	else
		wattron(core->ncur.bored, COLOR_PAIR(b->bored_color));
	mvwaddstr(core->ncur.bored, b->y, b->x, core->ncur.c_array[b->value]);
	wrefresh(core->ncur.bored);
}
