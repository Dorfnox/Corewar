/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:22:53 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/30 19:23:05 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Adds both the flag and flag function to the queue
*/

void			add_flag(t_queue **q, char *flag, void *flag_func)
{
	t_flag_queue	*q_item;

	if (!q || !flag || !flag_func)
		return ;
	*q = !*q ? initq() : *q;
	q_item = malloc(sizeof(t_flag_queue));
	if (!q_item)
		corewar_error("Failed to malloc in add_flag\n", 0);
	q_item->flag = flag;
	q_item->flag_func = flag_func;
	enqueue(*q, q_item);
}

/*
**	Flag handler moves av to the flag AFTER the last valid flag,
**	therefore, any extra flag handling can be done outside of the handler.
*/

unsigned int	flag_handler(t_corewar *core, char ***av)
{
	unsigned int	(*flag_func)(t_corewar *, char ***);

	if (isemptyq(core->flag_queue) || !av || !*av || !**av)
		return (1);
	while (**av)
	{
		flag_func = search_flag_queue(core->flag_queue->first, **av);
		if (!flag_func || !flag_func(core, av))
		{
			clean_flag_queue(&core->flag_queue);
			return (0);
		}
		++(*av);
	}
	clean_flag_queue(&core->flag_queue);
	return (1);
}

/*
**	Connects the given flag with a function pointer to return from the
**	flag queue.
*/

void			*search_flag_queue(t_node *n, char *flag)
{
	t_flag_queue	*q_item;

	while (n)
	{
		q_item = n->content;
		if (SE_(q_item->flag, flag))
			return ((void *)q_item->flag_func);
		n = n->next;
	}
	return (NULL);
}

void			clean_flag_queue(t_queue **q)
{
	while (!isemptyq(*q))
		free(dequeue(*q));
	ft_memdel((void **)q);
}
