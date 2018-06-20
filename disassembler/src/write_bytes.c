/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:22:59 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/19 18:23:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

uint8_t		*parse_encoding_byte(uint8_t content)
{
	static uint8_t	encoding_byte[4];

	encoding_byte[0] = (content >> 6) & 0b11;
	encoding_byte[1] = (content >> 4) & 0b11;
	encoding_byte[2] = (content >> 2) & 0b11;
	encoding_byte[3] = (content >> 0) & 0b11;
	return (encoding_byte);
}

void		write_instruction(int fd, t_operation *op)
{
	write(fd, ft_str256(3, "\t", op->name, " "), ft_strlen(ft_str256(0)));
}

void		write_reg(int fd, t_operation *op, uint8_t reg, int comma)
{
	static char	buff[5];
	uint8_t		to_write;

	if (IS_INVALID_REGISTER(reg))
		INSTR_ERR(ft_str128(2, op->name, " -- invalid register argument"));
	to_write = 0;
	buff[to_write++] = 'r';
	if (reg > 9)
	{
		buff[to_write++] = '1';
		buff[to_write++] = (reg % 10) + '0';
	}
	else
		buff[to_write++] = reg + '0';
	if (comma)
	{
		buff[to_write++] = ',';
		buff[to_write++] = ' ';
	}
	else
		buff[to_write++] = '\n';
	write(fd, buff, to_write);
}

uint16_t	write_dir(int fd, uint8_t *val, int len, int comma)
{
	static char	buff[13];
	static char num_buff[10];
	uint8_t		to_write;
	uint32_t	value;
	uint8_t		i;

	i = 0;
	value = 0;
	to_write = 0;
	buff[to_write++] = '%';
	value |= (uint32_t)*(val + 0) << (len == 4 ? 24 : 8);
	value |= (uint32_t)*(val + 1) << (len == 4 ? 16 : 0);
	value |= (len == 4) ? ((uint32_t)*(val + 2) << 8) : 0;
	value |= (len == 4) ? ((uint32_t)*(val + 3) << 0) : 0;
	!value ? (buff[to_write++]) = '0' : 0;
	while (value)
		if ((num_buff[i++] = (value % 10) + '0'))
			value /= 10;
	while (i--)
		buff[to_write++] = num_buff[i];
	buff[to_write++] = comma ? ',' : '\n';
	comma ? (buff[to_write++] = ' ') : 0;
	write(fd, buff, to_write);
	return (len);
}

uint16_t	write_indir(int fd, uint8_t *val, int comma)
{
	static char	buff[13];
	static char num_buff[10];
	uint8_t		to_write;
	uint32_t	value;
	uint8_t		i;

	value = 0;
	to_write = 0;
	value |= (uint32_t)*(val + 0) << 24;
	value |= (uint32_t)*(val + 1) << 16;
	value |= (uint32_t)*(val + 2) << 8;
	value |= (uint32_t)*(val + 3) << 0;
	!value ? (buff[to_write++]) = '0' : 0;
	i = 0;
	while (value)
		if ((num_buff[i++] = (value % 10) + '0'))
			value /= 10;
	while (i--)
		buff[to_write++] = num_buff[i];
	buff[to_write++] = comma ? ',' : '\n';
	comma ? (buff[to_write++] = ' ') : 0;
	write(fd, buff, to_write);
	return (4);
}