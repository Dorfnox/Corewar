/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:43 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

/*
**	ST functions
*/

uint16_t	st_(int fd, t_operation *op, uint8_t *content)
{
	uint8_t	*eb;
	uint8_t	bytes_read;

	write_instruction(fd, op);
	bytes_read = 0;
	eb = parse_encoding_byte(content[bytes_read++]);
	if (BAD_EB || EB0 != REGISTER || EB1 == 0 || EB1 == DIRECT)
	{
		INSTR_ERR(ft_str128(2, op->name, " -- invalid encoding byte"));
	}
	if (IS_INVALID_REGISTER(content[bytes_read]))
	{
		INSTR_ERR(ft_str128(2, op->name, " -- argument 1 is invalid register"));
	}
	write_reg(fd, content[bytes_read++], 1);
	if (EB1 == REGISTER)
	{
		write_reg(fd, content[bytes_read++], 1);
	}
	else if (EB1 == INDIRECT)
	{
		write_dir(fd, &content[bytes_read], 4, 0);
		bytes_read += 4;
	}
	return (bytes_read);
}
