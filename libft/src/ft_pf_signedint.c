/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_signedint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:38:15 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/04 13:55:31 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns ONLY the number WITHOUT a sign character.
*/

static char	*ft_intmax_to_ascii(intmax_t val, int base, char *b)
{
	char		*s;
	size_t		len;
	intmax_t	tmp;
	int			flag;

	len = 1;
	tmp = val;
	while (tmp /= 10)
		len++;
	flag = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (val == INTMAX_MIN)
	{
		val = (INTMAX_MIN + 1) * -1;
		flag = 1;
	}
	val *= (val < 0) ? -1 : 1;
	while (len--)
	{
		s[len] = (flag ? b[((INTMAX_MIN % base) * -1)] : b[val % base]);
		flag = 0;
		val /= base;
	}
	return (s);
}

static int	add_fieldwidth(char **str, char **chars, t_printf *p)
{
	char	*tmp;
	char	*tmp2;

	if (chars[0][0] == '0')
	{
		if (PID->f_sign != -1 || PID->f_space != -1 || PID->fmt->im < 0)
		{
			tmp = ft_strsub(*str, 0, 1);
			tmp2 = ft_strsub(*str, 1, ft_strlen(*str) - 1);
			tmp = ft_strfjoin(&tmp, *chars);
			tmp = ft_strfjoin(&tmp, tmp2);
			ft_strdeltwo(chars, &tmp2);
		}
		else
			tmp = ft_strfjoin(chars, *str);
		ft_strdel(str);
	}
	else
	{
		tmp = ft_strfjoin((p->pid->f_ladj != -1 ? str : chars),
				(p->pid->f_ladj != -1 ? *chars : *str));
		ft_strdel(p->pid->f_ladj != -1 ? chars : str);
	}
	*str = tmp;
	return ((int)ft_strlen(*str));
}

static int	add_sign(char **intmax_str, t_printf *p)
{
	char	*sign;

	if (!(sign = ft_strnew(1)))
		return (0);
	if (p->pid->fmt->im < 0)
	{
		sign[0] = '-';
	}
	else
		sign[0] = p->pid->f_sign != -1 ? '+' : ' ';
	if (!(sign = ft_strfjoin(&sign, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = sign;
	return ((int)ft_strlen(*intmax_str));
}

static int	add_precision(char **intmax_str, size_t num_of_zeros)
{
	char	*tmp;

	if (!(tmp = ft_strofchars('0', num_of_zeros)))
		return (0);
	if (!(tmp = ft_strfjoin(&tmp, *intmax_str)))
		return (0);
	ft_strdel(intmax_str);
	*intmax_str = tmp;
	return ((int)ft_strlen(*intmax_str));
}

int			pf_signedint(t_printf *p)
{
	char		*s;
	char		*tmp;
	char		pad;
	int			s_len;

	if (!(s = (PID->precision == 0 && PID->fmt->im == 0) ? ft_strnew(0) :
				ft_intmax_to_ascii(p->pid->fmt->im, p->pid->base,
					"0123456789ABCDEF")))
		return (-1);
	pad = (p->pid->f_zero != -1 ? '0' : ' ');
	s_len = ft_strlen(s);
	if (p->pid->precision > s_len)
		if (!(s_len = add_precision(&s, p->pid->precision - s_len)))
			return (-1);
	if (p->pid->f_sign != -1 || p->pid->f_space != -1 || p->pid->fmt->im < 0)
		if (!(s_len = add_sign(&s, p)))
			return (-1);
	if (p->pid->field_width > s_len)
		if ((tmp = ft_strofchars(pad, p->pid->field_width - s_len)))
			if (!(s_len = add_fieldwidth(&s, &tmp, p)))
				return (-1);
	ft_putstr(s);
	free(s);
	return (s_len);
}
