/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_set_percentid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:22:22 by bpierce           #+#    #+#             */
/*   Updated: 2017/12/20 20:04:17 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** set initial flags -
** #   : Alternate form (octal prints 066, 034... | hex prints 0x66, 0x34...)
** 0   : Fill field width with 0's.
** -   : Fill the left space with 'Field Width' chars.
** ' ' : Leave blank before a positive number (doesn't apply to negative).
** +   : Must place sign '-' or '+'.
*/

int		set_pf_flags(t_printf **p, char *s, int j)
{
	while (s[j] == '#' || s[j] == '0' ||
			s[j] == '-' || s[j] == ' ' || s[j] == '+')
	{
		if (s[j] == '#')
			(*p)->pid->f_alt = 1;
		if (s[j] == '0')
			(*p)->pid->f_zero = 1;
		if (s[j] == '-')
			(*p)->pid->f_ladj = 1;
		if (s[j] == ' ')
			(*p)->pid->f_space = 1;
		if (s[j] == '+')
			(*p)->pid->f_sign = 1;
		j++;
	}
	return (j);
}

/*
** Set minimum field width - you must always display full value,
** unless it is less than the field width, im which case
** pad the extra space with appropriate padding character.
*/

int		set_pf_fieldwidth(t_printf **p, char *s, int j)
{
	int		field_width;

	field_width = 0;
	if (ft_isdigit(s[j]))
		field_width = ft_atoi(&s[j]);
	while (ft_isdigit(s[j]))
		j++;
	if (field_width > 0)
		(*p)->pid->field_width = field_width;
	return (j);
}

/*
** Precision controls the MINIMUM number of digits to appear -
** this will add 0's if digit length is less than precision -
** or the MAXIMUM number of characters to appear in strings.
** If initial '.' exists, set precision as next number given or 0.
*/

int		set_pf_precision(t_printf **p, char *s, int j)
{
	int		precision;

	precision = 0;
	if (s[j] == '.')
	{
		j++;
		if (ft_isdigit(s[j]))
			precision = ft_atoi(&s[j]);
		else if (!(ft_isconversionchar(s[j]) || ft_islengthchar(s[j])))
			return (-1);
		while (ft_isdigit(s[j]))
			j++;
		(*p)->pid->precision = precision;
	}
	return (j);
}

/*
** If the size of the argument is specified, set length.
** First return is for lengths with two characters (hh, ll).
** Second return is for lengths with one character (h, l, j, z).
** Here are some lengths (smallest to largest) for reference:
** bool -> char -> short int -> int ->
** unsigned int -> long -> unsigned ->
** long long -> float -> double -> long double
*/

int		set_pf_length(t_printf **p, char *s, int j)
{
	if (ft_islengthchar(s[j]))
	{
		if ((s[j] == 'h' && s[j + 1] == 'h') ||
				(s[j] == 'l' && s[j + 1] == 'l'))
		{
			if (s[j + 1] == 'h')
				(*p)->pid->len = L_HH;
			else if (s[j + 1] == 'l')
				(*p)->pid->len = L_LL;
			return (j + 2);
		}
		else if (s[j] == 'h')
			(*p)->pid->len = L_H;
		else if (s[j] == 'l')
			(*p)->pid->len = L_L;
		else if (s[j] == 'j')
			(*p)->pid->len = L_J;
		else if (s[j] == 'z')
			(*p)->pid->len = L_Z;
		return (j + 1);
	}
	return (j);
}

/*
** Sets conversion type given. If none given, or '\0', returns error (-1).
*/

int		set_pf_type(t_printf **p, char *s, int j)
{
	if (ft_isconversionchar(s[j]))
	{
		(*p)->type = ((s[j] == 's' || s[j] == 'S') ? S_TYPE : (*p)->type);
		(*p)->type = ((s[j] == 'c' || s[j] == 'C') ? C_TYPE : (*p)->type);
		(*p)->type = ((s[j] == 'd' || s[j] == 'i') ? DI_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'D' ? DD_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'o' ? O_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'O' ? OO_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'u' ? U_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'U' ? UL_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'x' ? X_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'X' ? XX_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'p' ? P_TYPE : (*p)->type);
		(*p)->type = (s[j] == '%' ? PCNT_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'b' ? B_TYPE : (*p)->type);
		(*p)->type = (s[j] == 'B' ? BB_TYPE : (*p)->type);
		(*p)->pid->base = (s[j] == 'x' || s[j] == 'X' ? 16 : (*p)->pid->base);
		(*p)->pid->base = (s[j] == 'o' || s[j] == 'O' ? 8 : (*p)->pid->base);
		(*p)->pid->base = (s[j] == 'b' || s[j] == 'B' ? 2 : (*p)->pid->base);
		(*p)->pid->xbase = (s[j] == 'X' ? 1 : -1);
		F_ALT = (s[j] == 'x' || s[j] == 'X') && F_ALT != -1 ? 16 : F_ALT;
		F_ALT = (s[j] == 'o' || s[j] == 'O') && F_ALT != -1 ? 8 : F_ALT;
		return ((*p)->type == -1 ? -1 : j + 1);
	}
	return (-1);
}
