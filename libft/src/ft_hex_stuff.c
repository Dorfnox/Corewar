/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:52:10 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/28 13:16:50 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes a character string and converts it to a string of equivalent
**	hex characters.
*/

char		*convert_string_to_hex_string(char *s)
{
	char	*hex_string;
	char	*hex;
	int		len;
	int		i;

	if ((len = ft_strlen(s)) == 0)
		return (0);
	len *= 2;
	if (!(hex_string = malloc(len + 1)))
		return (0);
	i = 0;
	hex = "0123456789ABCDEF";
	while (i < len)
	{
		hex_string[i++] = hex[((*s) >> 4) & 0xF];
		hex_string[i++] = hex[(*s) & 0xF];
		++s;
	}
	hex_string[i] = 0;
	return (hex_string);
}

/*
** Converts the hex char (ex: 'A') to it's 4-bit (ex: 1010) equivalent
*/

char		convert_hex_char_to_4bit(uint8_t c)
{
	if (c > 47 && c < 58)
		return (c - 48);
	else if (c > 64 && c < 71)
		return (c - 55);
	else if (c > 96 && c < 103)
		return (c - 97);
	return (0);
}

/*
**	Generates a string of hex characters (ex: 0245FD3A9), given size
*/

char		*random_hex_string(size_t size)
{
	char	*x;
	int		buff_size;
	int		ret;
	int		fd;
	char	buff[2 + (size / 2)];

	if (!size || (x = NULL))
		return (NULL);
	buff_size = (size / 2) ? (size / 2) : 1;
	if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		return (NULL);
	while (ft_strlen(x) != size)
	{
		free(x);
		ret = read(fd, buff, buff_size);
		if (ret < buff_size || (buff[buff_size] = 0))
			return (close(fd) == 0 ? NULL : NULL);
		if (!(x = convert_string_to_hex_string(buff)))
			return (close(fd) == 0 ? NULL : NULL);
	}
	close(fd);
	x[size] = 0;
	return (x);
}

/*
**	Takes a string and converts it to a 64-bit value
**	Send through the first parameter if you just want the uint64_t
**	Send through the second parameter if you want to move the string as well
**	WARNING: Functions should not be done this way, but I was feeling lazy.
*/

uint64_t	str_to_64bit(char *s, char **s2)
{
	int			i;
	uint64_t	message;

	if ((!s && !s2) || (s && s2))
		return (0);
	i = -1;
	message = 0;
	s = s ? s : *s2;
	while (*s && ++i < 8)
	{
		message |= ((uint64_t)(*s) << (56 - (i * 8)));
		++s;
	}
	if (s2)
		*s2 = s;
	return (message);
}

