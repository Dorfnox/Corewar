/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:22 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

/*
**	0x10 - AFF...?
*/

uint16_t	aff_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t		*eb;
	uint16_t	bytes_read;

	write_instruction(fd, op);
	bytes_read = 0;
	eb = parse_encoding_byte(content[bytes_read++]);
	if (BAD_EB || EB0 != REGISTER || EB1 || EB2)
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	write_reg(fd, op, content[bytes_read++], 1);
	return (bytes_read);
}
