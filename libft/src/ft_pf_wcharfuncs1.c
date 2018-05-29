/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_wcharfuncs1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:02:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/26 14:50:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wstrlen(wchar_t *s)
{
	wchar_t	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

int			num_of_bytes(unsigned int ui)
{
	if (ui <= 127)
		return (1);
	else if (ui <= 2047)
		return (2);
	else if (ui <= 65535)
		return (3);
	return (4);
}

wchar_t		*ft_wstrnew(size_t len)
{
	wchar_t	*str;

	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * len + 1)))
		return (NULL);
	ft_memset(str, L'\0', len + 1);
	return (str);
}

wchar_t		*ft_wstrsub(wchar_t *ws, size_t start, size_t len)
{
	wchar_t	*newstr;
	size_t	i;

	if (ws == NULL)
		return (NULL);
	i = 0;
	if (!(newstr = ft_wstrnew(len)))
		return (NULL);
	while (ws[start] && i < len)
	{
		newstr[i] = ws[start];
		i++;
		start++;
	}
	newstr[i] = L'\0';
	return (newstr);
}

/*
** Returns the number of bytes 'put'
*/

void		ft_putwchar(wchar_t wi)
{
	unsigned int ui;

	ui = (unsigned int)wi;
	if (ui < 128)
		ft_putchar(ui);
	else if (ui < 2048)
	{
		ft_putchar(192 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
	else if (ui < 65536)
	{
		ft_putchar(224 | (ui >> 12 & 63));
		ft_putchar(128 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
	else
	{
		ft_putchar(240 | (ui >> 18 & 63));
		ft_putchar(128 | (ui >> 12 & 63));
		ft_putchar(128 | (ui >> 6 & 63));
		ft_putchar(128 | (ui & 63));
	}
}
