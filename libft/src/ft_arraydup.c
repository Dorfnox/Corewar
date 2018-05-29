/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:12:27 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/22 20:08:42 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char **old)
{
	char	**new;
	int		i;
	int		j;

	if (!old || (i = 0) == 1)
		return (NULL);
	while (old[i])
		++i;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	j = i;
	i = -1;
	while (++i < j)
	{
		if (!(new[i] = ft_strdup(old[i])))
		{
			while (i >= 0)
				free(new[i--]);
			free(new);
			return (NULL);
		}
	}
	new[i] = NULL;
	return (new);
}
