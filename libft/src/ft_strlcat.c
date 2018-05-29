/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:00:07 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:01:13 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dst_len;
	size_t	src_len;

	i = -1;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (dst_len);
	while (src[++i] && (dst_len + i) < size - 1)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	if (dst_len < size)
		return (dst_len + src_len);
	return (src_len + size);
}
