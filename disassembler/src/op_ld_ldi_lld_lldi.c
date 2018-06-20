/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

/*
**	Load functions
*/

uint16_t	ld_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t		*eb;
	uint16_t	bytes_read;

	write_instruction(fd, op);
	bytes_read = 0;
	eb = parse_encoding_byte(content[bytes_read++]);
	if (BAD_EB || (EB0 < 2 || EB1 != REGISTER || EB2))
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	if (EB0 == DIRECT)
		bytes_read += write_dir(fd, &content[bytes_read], 4, 1);
	else if (EB0 == INDIRECT)
		bytes_read += write_indir(fd, &content[bytes_read], 1);
	write_reg(fd, op, content[bytes_read++], 0);
	return (bytes_read);
}

uint16_t	ldi_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t		*eb;
	uint16_t	bytes_read;

	write_instruction(fd, op);
	bytes_read = 0;
	eb = parse_encoding_byte(content[bytes_read++]);
	if (BAD_EB || EB0 == 0 || EB1 == 0 || EB1 == INDIRECT || EB2 != REGISTER)
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	if (EB0 == REGISTER)
		write_reg(fd, op, content[bytes_read++], 1);
	else if (EB0 == DIRECT)
		bytes_read += write_dir(fd, &content[bytes_read], 2, 1);
	else if (EB0 == INDIRECT)
		bytes_read += write_indir(fd, &content[bytes_read], 1);
	if (EB1 == REGISTER)
		write_reg(fd, op, content[bytes_read++], 1);
	else if (EB1 == DIRECT)
		bytes_read += write_dir(fd, &content[bytes_read], 2, 1);
	write_reg(fd, op, content[bytes_read++], 0);
	return (bytes_read);
}
