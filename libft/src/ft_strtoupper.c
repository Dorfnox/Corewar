/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:28 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/22 18:49:10 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Turns all lower-case alphabet characters in string to upper case.
*/

void	ft_strtoupper(char **s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return ;
	while (s[0][i])
	{
		if (s[0][i] > 96 && s[0][i] < 123)
			s[0][i] -= 32;
		i++;
	}
	return ;
}
