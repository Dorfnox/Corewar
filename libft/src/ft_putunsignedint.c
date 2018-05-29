/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:25:17 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/03 17:11:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignedint(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunsignedint(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
