/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:50:52 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/20 18:02:38 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_remalloc:
**	- mallocs a space the size of new_size.
**	- copies content into the newly allocated space with the new size
**	- if there is no size difference, returns pointer to original content
*/

void		*ft_remalloc(void *content, size_t old_size, size_t new_size)
{
	void	*ret;

	if (!content || old_size == new_size)
		return (content);
	if (!new_size || !(ret = malloc(sizeof(new_size))))
	{
		free(content);
		return (NULL);
	}
	ft_memcpy(ret, content, old_size < new_size ? old_size : new_size);
	free(content);
	return (ret);
}
