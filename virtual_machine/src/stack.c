/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:59:02 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/04 14:59:44 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		insert_process(t_stack *s, t_process *p)
{
	t_node		*head;
	t_node		*n;
	t_process	*tmp;

	if (!(tmp = peek(s)))
		push(s, p);
	else
	{
		n = NULL;
		head = s->top;
		while ((tmp = peek(s)))
		{
			if (p->process_num > tmp->process_num)
				break ;
			n = s->top;
			s->top = s->top->next;
		}
		push(s, p);
		if (n)
			n->next = s->top;
		s->top = head;
	}
}
