/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:58:47 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/22 13:03:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_islengthchar(int c)
{
	size_t		len;

	len = ft_strlen(LENGTHS);
	while (len--)
		if (c == LENGTHS[len])
			return (1);
	return (0);
}

int		ft_isconversionchar(int c)
{
	size_t			len;

	len = ft_strlen(CONVERSIONS);
	while (len--)
		if (c == CONVERSIONS[len])
			return (1);
	return (0);
}

int		ft_isnumericconversionchar(int c)
{
	size_t			len;

	len = ft_strlen(NUM_CONVERSIONS);
	while (len--)
		if (c == NUM_CONVERSIONS[len])
			return (1);
	return (0);
}
