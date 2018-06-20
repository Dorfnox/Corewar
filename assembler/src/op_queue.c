/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:11:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 01:28:24 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_ops		*init_op_queue(void)
{
	t_ops	*new_queue;

	if (!(new_queue = (t_ops *)ft_memalloc(sizeof(t_ops))))
		MALLOC_ERROR();
	new_queue->labels = labelsInit(CAPACITY);
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void		enqueue_op(t_ops *queue, t_ast *node)
{
	if (!queue->first)
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
	queue->total_bytes += node->bytes;
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

t_ast		*create_ast(uint8_t op, uint8_t ecb, uint8_t bytes, t_token *params, uint8_t len_params)
{
	t_ast	 *node;

	if (!(node = (t_ast *)ft_memalloc(sizeof(t_ast))))
		MALLOC_ERROR();
	node->op = op;
	node->ecb = ecb;
	node->bytes = bytes;
	node->params = params;
	node->len_params = len_params;
	node->next = NULL;
	return (node);
}

uint8_t		op_queue_is_empty(t_ops *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}
