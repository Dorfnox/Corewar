/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:11:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/05 22:40:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_ops		*init_op_queue(void)
{
	t_ops	*new_queue;

	if (!(new_queue = (t_ops *)ft_memalloc(sizeof(t_ops))))
		asm_error(1, "Malloc error");
	new_queue->labels = labelsInit(CAPACITY);
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void		enqueue_op(t_ops *queue, uint8_t op, uint8_t ecb, uint8_t bytes, t_token *params)
{
	t_ast	 *node;

	if (!(node = (t_ast *)ft_memalloc(sizeof(t_ast))))
		asm_error(1, "Malloc error");
	node->op = op;
	node->ecb = ecb;
	node->bytes = bytes;
	node->params = params;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
	queue->total_bytes += bytes;
	queue->number_of_ops++;
}

t_ast		*dequeue_op(t_ops *queue)
{
	t_ast	*tmp_node;

	if (!queue || !queue->first)
		return (NULL);
	else
	{
		tmp_node = queue->first;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last = NULL;
		queue->number_of_ops--;
		queue->total_bytes -= tmp_node->bytes;
		return (tmp_node);
	}
}

// char			*peek_queue(t_ops *queue)
// {
// 	if (!queue || !queue->first)
// 		exit_error();
// 	return (queue->first->s);
// }
