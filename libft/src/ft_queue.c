/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:42:26 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/26 13:24:41 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue		*initq(void)
{
	t_queue	*q;

	if (!(q = malloc(sizeof(t_queue))))
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return (q);
}

void		enqueue(t_queue *q, void *content)
{
	t_node	*new_node;

	if (!(new_node = malloc(sizeof(t_node))))
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (!(q->first))
		q->first = new_node;
	else
		q->last->next = new_node;
	q->last = new_node;
	++q->size;
}

void		*dequeue(t_queue *q)
{
	void	*content;
	t_node	*to_delete;

	if (!(q->first))
		return (NULL);
	content = q->first->content;
	to_delete = q->first;
	q->first = q->first->next;
	q->last = q->first ? q->last : NULL;
	free(to_delete);
	--q->size;
	return (content);
}

void		*peekq(t_queue *q)
{
	return (q && q->first ? q->first->content : NULL);
}

int			isemptyq(t_queue *q)
{
	return (q && q->first ? 0 : 1);
}
