/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varraynew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:28:38 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/17 19:10:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_varraynew(int width, int height, size_t size)
{
	void	**array;
	int		i;

	if (!(width > 0 && height > 0 && size > 0))
		return (NULL);
	if (!(array = malloc(sizeof(void *) * height)))
		return (NULL);
	i = -1;
	while (++i < height)
	{
		if (!(array[i] = malloc(size * width)))
		{
			ft_varraydel(&array, i);
			return (NULL);
		}
		ft_bzero(array[i], size * width);
	}
	return (array);
}
