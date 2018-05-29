/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_widechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 13:32:22 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/24 13:40:35 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_widechar(t_printf *p)
{
	int		fw;

	fw = 0;
	if (p->pid->f_ladj != -1)
	{
		ft_putwchar(p->pid->fmt->wc);
		while (++fw < p->pid->field_width)
			ft_putchar(' ');
	}
	else
	{
		while (++fw < p->pid->field_width)
			ft_putchar(' ');
		ft_putwchar(p->pid->fmt->wc);
	}
	return (fw);
}
