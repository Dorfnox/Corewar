/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupuntil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:41:14 by aderby            #+#    #+#             */
/*   Updated: 2017/09/06 16:02:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdupuntil(const char *s, const char c)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s && c)
	{
		if (s[i] != '\0')
		{
			while (s[i] != c && s[i])
				i++;
			if ((str = ft_strsub(s, 0, i)))
				return (str);
		}
	}
	return (NULL);
}
