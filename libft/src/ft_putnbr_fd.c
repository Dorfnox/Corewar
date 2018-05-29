/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:25:17 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/09 17:28:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		if (flag == 1)
			ft_putchar_fd('8', fd);
		else
			ft_putchar_fd(((n % 10) + '0'), fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}
