/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrayrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:08:09 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/31 13:37:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reverses the given array of pointers
*/

void	ft_varrayrev(void **array, int size_of_array)
{
	int		beg;
	void	*tmp;

	if (!array || !(*array) || size_of_array < 2)
		return ;
	beg = 0;
	--size_of_array;
	while (1)
	{
		tmp = array[beg];
		array[beg] = array[size_of_array];
		array[size_of_array] = tmp;
		++beg;
		--size_of_array;
		if (beg >= size_of_array)
			return ;
	}
}
