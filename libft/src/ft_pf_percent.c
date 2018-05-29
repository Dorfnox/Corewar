/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:14:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 18:06:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_fieldwidth(char **s, int f_ladj, int spaces, char pad)
{
	char	*tmp;

	if (!(tmp = ft_strofchars(pad, spaces)))
		return (NULL);
	if (f_ladj != -1)
	{
		if (!(*s = ft_strfjoin(s, tmp)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(tmp = ft_strfjoin(&tmp, *s)))
			return (NULL);
		ft_strdel(s);
		*s = tmp;
	}
	return (*s);
}

int			pf_percent(t_printf *p)
{
	char	pad;
	char	*s;
	int		s_len;
	int		spaces;

	if (!(s = ft_strdup("%")))
		return (-1);
	pad = (p->pid->f_zero != -1) ? '0' : ' ';
	pad = (p->pid->f_ladj != -1) ? ' ' : pad;
	s_len = 1;
	spaces = p->pid->field_width - s_len;
	if (spaces > 0)
		if (!(s = add_fieldwidth(&s, p->pid->f_ladj, spaces, pad)))
			return (-1);
	ft_putstr(s);
	s_len = ft_strlen(s);
	free(s);
	return (s_len);
}
