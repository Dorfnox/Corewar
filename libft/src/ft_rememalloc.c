/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rememalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:50:52 by bpierce           #+#    #+#             */
/*   Updated: 2018/04/04 18:31:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_rememalloc:
**	- mallocs a space the size of new_size.
**	- copies content into the newly allocated space with the new size
**	- if there is no size difference, returns pointer to original content
*/

void		*ft_rememalloc(void *content, size_t old_size, size_t new_size)
{
	void	*ret;

	if (!content || old_size == new_size)
		return (content);
	if (!new_size || !(ret = ft_memalloc(new_size)))
	{
		free(content);
		return (NULL);
	}
	ft_memcpy(ret, content, MIN(old_size, new_size));
	free(content);
	return (ret);
}
