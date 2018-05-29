/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:38:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/29 18:02:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns ONLY the number WITHOUT a sign character.
*/

static char	*ft_uintmax_to_ascii(uintmax_t val, int base, int xbase)
{
	int			s_len;
	char		*b_array;
	char		*s;
	uintmax_t	tmp_val;

	b_array = "0123456789ABCDEF";
	tmp_val = val;
	s_len = 0;
	while (++s_len && tmp_val >= (uintmax_t)base)
		tmp_val /= base;
	if (!(s = ft_strnew(s_len)))
		return (NULL);
	while (s_len--)
	{
		s[s_len] = b_array[val % base];
		val /= base;
	}
	(xbase == -1) ? ft_strtolower(&s) : 0;
	return (s);
}

static int	add_fieldwidth(char **str, char **chars, t_printf *p)
{
	char	*tmp;
	char	*tmp2;

	if (chars[0][0] == '0')
	{
		if (p->pid->f_alt == 16 || p->pid->f_alt == 8)
		{
			tmp = ft_strsub(*str, 0, (p->pid->f_alt == 16 ? 2 : 1));
			tmp2 = ft_strsub(*str, (p->pid->f_alt == 16 ? 2 : 1),
					ft_strlen(*str) - (p->pid->f_alt == 16 ? 2 : 1));
			tmp = ft_strffjoin(&tmp, chars);
			tmp = ft_strffjoin(&tmp, &tmp2);
		}
		else
			tmp = ft_strffjoin(chars, str);
	}
	else
	{
		tmp = ft_strffjoin((p->pid->f_ladj != -1 ? str : chars),
				(p->pid->f_ladj != -1 ? chars : str));
	}
	*str = tmp;
	return (ft_strlen(*str));
}

static int	add_alt(char **str, int xbase, int f_alt, int type)
{
	char	*alt;

	if ((f_alt == 16 && ft_strlen(*str) > 0 && (*str)[0] != '0') ||
		type == P_TYPE || type == BB_TYPE)
	{
		if (!(alt = ft_strnew(2)))
			return (-1);
		alt[0] = '0';
		alt[1] = xbase != -1 ? 'X' : 'x';
		alt[1] = (type == BB_TYPE) ? 'b' : alt[1];
		if (!(*str = ft_strffjoin(&alt, str)))
			return (-1);
	}
	else if (f_alt == 8)
	{
		if ((*str)[0] != '0')
		{
			if (!(alt = ft_strnew(1)))
				return (-1);
			alt[0] = '0';
			if (!(*str = ft_strffjoin(&alt, str)))
				return (-1);
		}
	}
	return (ft_strlen(*str));
}

static int	add_prec(char **str, int num_of_zeros, int alt)
{
	char	*tmp;

	if (num_of_zeros > 0)
	{
		if (!(tmp = ft_strofchars('0', num_of_zeros)))
			return (-1);
		if (!(*str = ft_strffjoin(&tmp, str)))
			return (-1);
	}
	else if (alt == 8)
	{
		if ((add_alt(str, 0, alt, -1)) == -1)
			return (-1);
	}
	return (ft_strlen(*str));
}

int			pf_unsignedint(t_printf *p)
{
	char		*s;
	char		*tmp;
	char		pad;
	int			s_len;

	if (!(s = (PID->precision == 0 && PID->base != 10 && PID->fmt->uim == 0
				? ft_strnew(0)
				: ft_uintmax_to_ascii(PID->fmt->uim, PID->base, PID->xbase))))
		return (-1);
	pad = (PID->f_zero != -1 ? '0' : ' ');
	s_len = ft_strlen(s);
	if (PID->precision > s_len || PID->f_alt == 8)
		if ((s_len = add_prec(&s, PID->precision - s_len, PID->f_alt)) == -1)
			return (-1);
	if (PID->f_alt != -1 && (PID->base == 16 || PID->base == 2))
		if ((s_len = add_alt(&s, PID->xbase, PID->f_alt, p->type)) == -1)
			return (-1);
	if (PID->field_width > s_len &&
			(tmp = ft_strofchars(pad, p->pid->field_width - s_len)))
		if ((s_len = add_fieldwidth(&s, &tmp, p)) == -1)
			return (-1);
	ft_putstr(s);
	free(s);
	return (s_len);
}
