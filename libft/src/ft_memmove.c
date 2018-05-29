/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:32:53 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/04 16:18:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (newsrc < newdst)
	{
		while (len > 0)
		{
			newdst[len - 1] = newsrc[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
