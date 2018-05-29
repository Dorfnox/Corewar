/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:58:54 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:56:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_new;
	unsigned char	*s_new;

	i = 0;
	c_new = (unsigned char)c;
	s_new = (unsigned char *)s;
	while (i < n)
	{
		if (s_new[i] == c_new)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
