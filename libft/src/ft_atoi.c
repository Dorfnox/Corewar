/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:02:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/09 22:14:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		sign;
	int		total;

	sign = 1;
	total = 0;
	while (ft_iswhitespace(*str) == 1)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		total = (total * 10) + (*str - '0');
		str++;
	}
	return (sign * total);
}
