/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:12:23 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 17:43:34 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!(little_len = ft_strlen(little)))
		return ((char *)big);
	while (*big && len-- >= little_len)
	{
		if (*big == *little && ft_memcmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
