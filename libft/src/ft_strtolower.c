/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/21 15:03:12 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Turns all upper-case alphabet characters in string to lower case.
*/

void	ft_strtolower(char **s)
{
	int	i;

	i = 0;
	while (s[0][i])
	{
		if (s[0][i] > 64 && s[0][i] < 91)
			s[0][i] += 32;
		i++;
	}
	return ;
}
