/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:30:44 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 18:17:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_all_the_things(t_printf **head)
{
	t_printf	*tmp;

	if (*head)
	{
		while (*head)
		{
			if ((*head)->type == STRING_TYPE)
				ft_strdel(&((*head)->str));
			else if ((*head)->type != -1)
			{
				if ((*head)->pid)
				{
					if ((*head)->pid->fmt)
						free((*head)->pid->fmt);
					free((*head)->pid);
				}
			}
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}
