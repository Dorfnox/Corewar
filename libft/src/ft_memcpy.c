/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:58:54 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:00:57 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;
	size_t			i;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (dst);
}
