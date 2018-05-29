/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:51:00 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/13 16:06:30 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	else
	{
		while (s[i])
		{
			if (s[i] == c)
			{
				j = 1;
				k = i;
			}
			i++;
		}
		if (j == 1)
			return ((char *)s + k);
	}
	return (NULL);
}
