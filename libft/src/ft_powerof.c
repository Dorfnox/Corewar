/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:31:54 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/21 12:14:17 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_powerof(long long num, int power)
{
	int			i;
	long long	tmp;

	i = 0;
	if (power == 0)
		return (1);
	tmp = num;
	while (++i < power)
		num *= tmp;
	return (num);
}
