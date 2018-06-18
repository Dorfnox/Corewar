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

void		insert_process_at_bottom(t_corewar *core, t_stack *s, t_process *p)
{
	t_node		*head;
	t_node		*prev;

	if (s->top == NULL)
		push(s, p);
	else
	{
		head = s->top;
		prev = NULL;
		while (s->top)
		{
			prev = s->top;
			s->top = s->top->next;
		}
		push(s, p);
		if (prev)
			prev->next = s->top;
		s->top = head;
	}
	if (s->size == 1)
		VIZ(push_process_cursor(core, p));
}

/*
**	Adds to the cursor stack for the given index location
*/

void		push_process_cursor(t_corewar *core, t_process *process)
{
	t_board_node	*board;

	board = core->node_addresses[process->curr_pc->index];
	if (CE_2(process->op->instruct, fork_, lfork_))
	{
		while (!isemptys(&board->cursor_stack))
			pop(&board->cursor_stack);
	}
	push(&board->cursor_stack, process);
	draw_cursor(core, board);
}

void		pop_process_cursor(t_corewar *core, t_process *process)
{
	t_board_node		*board;
	static t_node		*p;
	static t_node		*prev;

	board = core->node_addresses[process->curr_pc->index];
	if (isemptys(&board->cursor_stack))
		return ;
	if (board->cursor_stack.size == 1 &&
		peeks(&board->cursor_stack) != process)
		return ;
	if (peeks(&board->cursor_stack) == process)
		pop(&board->cursor_stack);
	else
	{
		p = board->cursor_stack.top;
		while (peeks(&board->cursor_stack) != process)
		{
			prev = board->cursor_stack.top;
			board->cursor_stack.top = board->cursor_stack.top->next;
			if (board->cursor_stack.top == NULL)
			{
				board->cursor_stack.top = p;
				return ;
			}
		}
		pop(&board->cursor_stack);
		prev->next = board->cursor_stack.top;
		board->cursor_stack.top = p;
	}
	draw_cursor(core, board);
}

void		draw_cursor(t_corewar *core, t_board_node *b)
{
	t_process		*p;
	static uint64_t	i;

	if (core->flag.epilepsy)
	{
		wattron(core->ncur.bored, COLOR_PAIR((i++ % 3) + 5));
	}
	else if ((p = peeks(&b->cursor_stack)))
	{
	    wattron(core->ncur.bored, COLOR_PAIR(p->player->player_num + 4));
	}
	else
	{
		wattron(core->ncur.bored, COLOR_PAIR(b->bored_color));
	}
	mvwaddstr(core->ncur.bored, b->y, b->x,
		core->ncur.c_array[core->node_addresses[b->index]->value]);
	wrefresh(core->ncur.bored);
}
