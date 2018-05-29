/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:38:00 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:44:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = num_length(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	else if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}
	while (--len >= i)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
