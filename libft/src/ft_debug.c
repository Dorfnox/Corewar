/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:05:07 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/21 13:01:29 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_debug(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(IYELLOW, 2);
		ft_putstr_fd(" <--\n", 2);
		ft_putstr_fd(COLOR_OFF, 2);
		return (1);
	}
	return (0);
}
