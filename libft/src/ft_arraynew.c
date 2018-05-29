/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:28:38 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/21 17:01:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraynew(int width, int height)
{
	char	**array;
	int		i;

	if (!(array = malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(array[i] = malloc(sizeof(char) * (width + 1))))
			return (NULL);
		ft_bzero(array[i], width + 1);
		i++;
	}
	if (!(array[i] = malloc(sizeof(char))))
		return (NULL);
	array[i][0] = '\0';
	return (array);
}
