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

t_process	*new_process(t_corewar *core, t_player *player,
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
	VIZ(new_process_cursor(core, new));
	return (new);
}

void		insert_process(t_stack *s, t_process *p)
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
}

void		new_process_cursor(t_corewar *c, t_process *process)
{
	int start_x;
	int	start_y;

	start_x = process->curr_pc->index / 64;
	start_y = (process->curr_pc->index % 64) * 3;
	MALL_ERR((process->cursor = newwin(1, 2, start_x, start_y)), "ncurses");
	wattron(process->cursor, COLOR_PAIR(process->player->player_num + 4));
	mvwaddstr(process->cursor, 0, 0, c->ncur.c_array[process->curr_pc->value]);
	wrefresh(process->cursor);
}

void		move_process_cursor(t_corewar *c, t_process *process)
{
	static int	start_x;
	static int	start_y;

	start_x = process->curr_pc->index / 64;
	start_y = (process->curr_pc->index % 64) * 3;
	mvwin(process->cursor, start_x, start_y);
	mvwaddstr(process->cursor, 0, 0, c->ncur.c_array[process->curr_pc->value]);
	wrefresh(process->cursor);
}
