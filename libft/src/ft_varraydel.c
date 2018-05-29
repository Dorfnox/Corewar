/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varraydel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:08:09 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/17 19:19:30 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varraydel(void ***array, int size_of_array)
{
	int		i;

	if (!array || !(*array) || size_of_array < 1 || !(i = -1))
		return ;
	while (++i < size_of_array)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
	}
	free(*array);
	*array = NULL;
}
