/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_printlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:47:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/21 17:38:36 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Create new print list element.
*/

t_printf	*new_printlst(void)
{
	t_printf	*new;

	if (!(new = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (NULL);
	new->type = -1;
	new->print_func = NULL;
	new->str = NULL;
	new->pid = NULL;
	new->next = NULL;
	return (new);
}

/*
** Initializes p1, and points p2 to the head.
*/

int			initialize_printlst(t_printf **p1, t_printf **p2)
{
	if (!(*p1 = new_printlst()))
		return (0);
	*p2 = *p1;
	return (1);
}

/*
** Stores single, normal character in t_printf linked list
*/

int			storechar_printlst(t_printf **p, const char c, int i)
{
	int		pstr_len;

	if ((*p)->type == -1)
		(*p)->type = STRING_TYPE;
	else if ((*p)->type != STRING_TYPE)
	{
		(*p)->next = new_printlst();
		*p = (*p)->next;
		(*p)->type = STRING_TYPE;
	}
	if ((*p)->str == NULL)
	{
		if (!((*p)->str = ft_strnew(1)))
			return (-1);
		(*p)->str[0] = c;
	}
	else
	{
		pstr_len = ft_strlen((*p)->str);
		if (!((*p)->str = ft_strfresize(&((*p)->str), pstr_len + 1)))
			return (-1);
		(*p)->str[pstr_len] = c;
	}
	return (i + 1);
}

/*
** Iterate through printlst and print values
*/

int			print_printlst(t_printf **p)
{
	int			i;
	t_printf	*tmp;

	i = 0;
	tmp = *p;
	while (tmp)
	{
		if (tmp->type == STRING_TYPE)
		{
			ft_putstr(tmp->str);
			i += ft_strlen(tmp->str);
		}
		else
		{
			i += tmp->print_func(tmp);
		}
		tmp = tmp->next;
	}
	return (i);
}
