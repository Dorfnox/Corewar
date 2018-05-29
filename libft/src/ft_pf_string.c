/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:14:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 18:18:08 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_fieldwidth(char **s, int f_ladj, int num_spaces)
{
	char	*tmp;

	if (!(tmp = ft_strofchars(' ', num_spaces)))
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

int			pf_string(t_printf *p)
{
	char	*s;
	int		nsp;
	int		s_len;

	if (p->pid->fmt->s == NULL)
		if (!(p->pid->fmt->s = ft_strdup("(null)")))
			return (-1);
	if (p->pid->precision != -1)
	{
		s = ft_strsub(p->pid->fmt->s, 0, p->pid->precision);
		ft_strdel(&(p->pid->fmt->s));
		p->pid->fmt->s = s;
	}
	nsp = PID->field_width - ft_strlen(p->pid->fmt->s);
	if (nsp > 0)
		if (!(PID->fmt->s = add_fieldwidth(&(PID->fmt->s), PID->f_ladj, nsp)))
			return (-1);
	ft_putstr(p->pid->fmt->s);
	s_len = ft_strlen(p->pid->fmt->s);
	free(p->pid->fmt->s);
	return (s_len);
}
