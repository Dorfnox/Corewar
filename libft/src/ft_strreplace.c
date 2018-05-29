/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:13:20 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/28 19:20:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_finds(char *s, char *find, int flen)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (ft_strnequ(&s[i], find, flen))
		{
			i += flen - 1;
			++j;
		}
	}
	return (j);
}

char		*ft_strreplace(char *s, char *find, char *replace)
{
	char	*new;
	int		num;
	int		i;
	int		j;
	int		l[2];

	if (!s || !find || !replace || !(l[0] = ft_strlen(find)))
		return (NULL);
	if (!ft_strlen(s) || (j = 0))
		return (ft_strnew(0));
	if (!(num = num_of_finds(s, find, l[0])))
		return (ft_strdup(s));
	l[1] = ft_strlen(replace);
	if (!(new = ft_strnew(ft_strlen(s) - (num * l[0]) + (num * l[1]))))
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (ft_strnequ(&s[i], find, l[0]) && ((i += l[0] - 1) || !i))
			if (ft_strncpy(&new[j], replace, l[1]))
				if ((j += l[1]) || !j)
					continue ;
		new[j++] = s[i];
	}
	return (new);
}
