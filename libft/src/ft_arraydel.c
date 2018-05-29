/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:08:09 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/18 11:27:50 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydel(char ***array)
{
	int		i;

	if (!array || !(*array))
		return (NULL);
	i = -1;
	while ((*array)[++i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
	}
	free(*array);
	return ((*array = NULL));
}
