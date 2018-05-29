/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:53:04 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/15 18:50:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Builds a static string given 'num' of strings to concatenate together
** Stores 255 characters without 'overloading' the buffer
*/

char	*ft_str256(int num, ...)
{
	static char	s[256];
	char		*tmp;
	int			i;
	va_list		ap;

	if (num == 0)
		return (s);
	i = 0;
	s[255] = 0;
	va_start(ap, num);
	while (num--)
	{
		if ((tmp = va_arg(ap, char *)))
			while (i < 255 && *tmp)
				s[i++] = *(tmp++);
		if (tmp && *tmp)
			if ((s[251] = '.'))
				if ((s[252] = '.'))
					if ((s[253] = '.'))
						if ((s[254] = '\n'))
							break ;
	}
	s[i] = 0;
	va_end(ap);
	return (s);
}

/*
** Same thing, but with a bigger buffer
*/

char	*ft_str1024(int num, ...)
{
	static char	s[1024];
	char		*tmp;
	int			i;
	va_list		ap;

	if (num == 0)
		return (s);
	i = 0;
	s[1023] = 0;
	va_start(ap, num);
	while (num--)
	{
		if ((tmp = va_arg(ap, char *)))
			while (i < 1023 && *tmp)
				s[i++] = *(tmp++);
		if (tmp && *tmp)
			if ((s[1022] = '\n'))
				if ((s[1021] = '.'))
					if ((s[1020] = '.'))
						if ((s[1019] = '.'))
							break ;
	}
	s[i] = 0;
	va_end(ap);
	return (s);
}

/*
** Same thing, but with a smaller buffer
*/

char	*ft_str128(int num, ...)
{
	static char	s[128];
	char		*tmp;
	int			i;
	va_list		ap;

	if (num == 0)
		return (s);
	i = 0;
	s[127] = 0;
	va_start(ap, num);
	while (num--)
	{
		if ((tmp = va_arg(ap, char *)))
			while (i < 127 && *tmp)
				s[i++] = *(tmp++);
		if (tmp && *tmp)
			if ((s[126] = '\n'))
				if ((s[125] = '.'))
					if ((s[124] = '.'))
						if ((s[123] = '.'))
							break ;
	}
	s[i] = 0;
	va_end(ap);
	return (s);
}
