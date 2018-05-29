/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:13:34 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/11 16:30:45 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*my_list;

	my_list = (t_list *)malloc(sizeof(t_list));
	if (my_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		my_list->content = NULL;
		my_list->content_size = 0;
	}
	else
	{
		my_list->content = malloc(content_size);
		ft_memcpy(my_list->content, content, content_size);
		my_list->content_size = content_size;
	}
	my_list->next = NULL;
	return (my_list);
}
