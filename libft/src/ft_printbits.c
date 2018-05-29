/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:51:45 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/23 16:24:41 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Please print using single types.
**	Example:
**	uint64_t with a size of 8
**	uint32_t with a size of 4
*/

void		printbits_big_endian(void *array, size_t size)
{
	uint8_t	*a;
	char	buf[9];
	size_t	i;

	if (!array || !size)
		return ;
	i = 0;
	buf[8] = ' ';
	a = (uint8_t *)array;
	while (i++ < size)
	{
		buf[0] = (char)((*a >> 7) & 0x1) ? '1' : '0';
		buf[1] = (char)((*a >> 6) & 0x1) ? '1' : '0';
		buf[2] = (char)((*a >> 5) & 0x1) ? '1' : '0';
		buf[3] = (char)((*a >> 4) & 0x1) ? '1' : '0';
		buf[4] = (char)((*a >> 3) & 0x1) ? '1' : '0';
		buf[5] = (char)((*a >> 2) & 0x1) ? '1' : '0';
		buf[6] = (char)((*a >> 1) & 0x1) ? '1' : '0';
		buf[7] = (char)((*a >> 0) & 0x1) ? '1' : '0';
		write(1, buf, 9);
		i < size ? ++a : 0;
	}
	write(1, "\n", 1);
}

void		printbits_little_endian(void *array, size_t size)
{
	uint8_t	*a;
	char	buf[9];
	size_t	i;

	if (!array || !size)
		return ;
	i = size;
	buf[8] = ' ';
	a = (uint8_t *)array;
	a += (size - 1);
	while (i-- > 0)
	{
		buf[0] = (char)((*a >> 7) & 0x1) ? '1' : '0';
		buf[1] = (char)((*a >> 6) & 0x1) ? '1' : '0';
		buf[2] = (char)((*a >> 5) & 0x1) ? '1' : '0';
		buf[3] = (char)((*a >> 4) & 0x1) ? '1' : '0';
		buf[4] = (char)((*a >> 3) & 0x1) ? '1' : '0';
		buf[5] = (char)((*a >> 2) & 0x1) ? '1' : '0';
		buf[6] = (char)((*a >> 1) & 0x1) ? '1' : '0';
		buf[7] = (char)((*a >> 0) & 0x1) ? '1' : '0';
		write(1, buf, 9);
		i > 0 ? --a : 0;
	}
	write(1, "\n", 1);
}
