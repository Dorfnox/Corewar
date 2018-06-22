/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:22:53 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:45:30 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Initializes the flags with their flag functions
*/

void			init_flag_queue(t_queue *q)
{
	add_flag(q, "-n", flag_n);
	add_flag(q, "-d", flag_dump);
	add_flag(q, "-dump", flag_dump);
	add_flag(q, "-v", flag_viz);
	add_flag(q, "-viz", flag_viz);
	add_flag(q, "-s", flag_speed);
	add_flag(q, "-speed", flag_speed);
	add_flag(q, "-r", flag_rainbow);
	add_flag(q, "-rainbow", flag_rainbow);
	add_flag(q, "-a", flag_activity);
	add_flag(q, "-activity", flag_activity);
}

/*
**	Adds both the flag and flag function to the queue
*/

void			add_flag(t_queue *q, char *flag, void *flag_func)
{
	t_flag_queue	*q_item;

	if (!flag || !flag_func)
		return ;
	q_item = malloc(sizeof(t_flag_queue));
	if (!q_item)
		corewar_error("Failed to malloc in add_flag\n", 1);
	q_item->flag = ft_strdup(flag);
	q_item->flag_func = flag_func;
	enqueue(q, q_item);
}

/*
**	Flag handler moves av to the flag AFTER the last valid flag,
**	therefore, any extra flag handling can be done outside of the handler.
*/

unsigned int	flag_handler(t_corewar *core, char ***av)
{
	unsigned int	(*flag_func)(t_corewar *, char ***);
	t_queue			*q;

	q = &core->flag_queue;
	if (isemptyq(q) || !av || !*av || !**av)
		return (1);
	while (**av)
	{
		flag_func = search_flag_queue(q->first, **av);
		if (!flag_func || !flag_func(core, av))
			return (0);
		++(*av);
	}
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

void			clean_flag_queue(t_queue *q)
{
	t_flag_queue *q_item;

	while (!isemptyq(q))
	{
		q_item = dequeue(q);
		free(q_item->flag);
		free(q_item);
	}
}
