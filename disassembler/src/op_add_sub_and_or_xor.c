/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub_and_or_xor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 21:50:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

/*
**	Math - takes reg reg reg
**	- - - - - - - - - -
**	Add, Sub, XOR, OR, AND
*/

uint16_t	math_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t	*eb;

	write_instruction(fd, op);
	eb = parse_encoding_byte(*(content++));
	if (BAD_EB || EB0 != REGISTER || EB1 != REGISTER || EB2 != REGISTER)
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	if (content[0] > REG_NUMBER || content[0] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 1 is not a valid register"));
	if (content[1] > REG_NUMBER || content[1] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 2 is not a valid register"));
	if (content[2] > REG_NUMBER || content[2] < 1)
		INSTR_ERR(ft_str128(2, op->name, " -- arg 3 is not a valid register"));
	write_reg(fd, op, content[0], 1);
	write_reg(fd, op, content[1], 1);
	write_reg(fd, op, content[2], 0);
	return (4);
}

uint16_t	bitmath_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t		*eb;
	uint16_t	bytes_read;

	write_instruction(fd, op);
	bytes_read = 0;
	eb = parse_encoding_byte(*(content++));
	if (BAD_EB || EB0 == 0 || EB1 == 0 || EB2 != REGISTER)
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
	else if (EB1 == INDIRECT)
		bytes_read += write_indir(fd, &content[bytes_read], 1);
	write_reg(fd, op, content[bytes_read++], 0);
	return (bytes_read);
}
