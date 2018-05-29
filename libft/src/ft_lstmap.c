/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 14:33:03 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 15:39:42 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	head = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			tmp = f(lst);
			if (head == NULL)
			{
				new = ft_lstnew(tmp->content, tmp->content_size);
				head = new;
			}
			else
			{
				new->next = ft_lstnew(tmp->content, tmp->content_size);
				new = new->next;
			}
			lst = lst->next;
		}
	}
	return (head);
}
