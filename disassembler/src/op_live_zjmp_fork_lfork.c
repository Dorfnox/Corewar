/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:59:00 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

/*
** Takes direct numbers
*/

uint16_t	live_(int fd, t_operation *op, uint8_t *content)
{
	write_instruction(fd, op);
	write_dir(fd, content, 4, 0);
	return (4);
}

uint16_t	zjmp_(int fd, t_operation *op, uint8_t *content)
{
	write_instruction(fd, op);
	write_dir(fd, content, 2, 0);
	return (2);
}

uint16_t	fork_(int fd, t_operation *op, uint8_t *content)
{
	write_instruction(fd, op);
	write_dir(fd, content, 2, 0);
	return (2);
}

uint16_t	lfork_(int fd, t_operation *op, uint8_t *content)
{
	write_instruction(fd, op);
	write_dir(fd, content, 2, 0);
	return (2);
}
