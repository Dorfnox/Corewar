/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:08:21 by bpierce           #+#    #+#             */
/*   Updated: 2017/08/30 18:32:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If constnt is 1, more shading occurs, if constnt is 0.1, less shading occurs
*/

int		ft_shade_colour(int colour, double percent, double constant)
{
	double	red;
	double	green;
	double	blue;
	double	multiplier;

	red = (double)((colour >> 16) & 0x0000FF);
	green = (double)((colour >> 8) & 0x0000FF);
	blue = (double)(colour & 0x0000FF);
	multiplier = (100 / (percent * constant)) > 100 ? 100 :
		100 / (percent * constant);
	red *= multiplier / 100;
	green *= multiplier / 100;
	blue *= multiplier / 100;
	return (ft_rgb_to_hex((short)red, (short)green, (short)blue));
}
