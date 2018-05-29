/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:25:17 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/09 17:22:33 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int flag;

	flag = 0;
	if (n == -2147483648)
	{
		flag = 1;
		n += 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		if (flag == 1)
			ft_putchar('8');
		else
			ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
