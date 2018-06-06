/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:27:36 by dmontoya          #+#    #+#             */
/*   Updated: 2018/06/04 17:27:39 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

uint16_t 	get_index(uint16_t pc, uint8_t idx_byte1, uint8_t idx_byte2)
{
	return ((pc + ((((uint16_t)idx_byte1 << 8) | (u_int16_t)idx_byte2) % IDX_MOD)) % MEM_SIZE);
}

void		write_number_to_board(t_board_node *board, uint8_t *number)
{
	uint8_t i;

	i = 0;
	while (i < REG_SIZE)
	{
		board->value = number[i++];
		board = board->next;
	}
}

void		write_board_to_register(uint8_t *reg, t_board_node *board)
{
	uint8_t i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg[i++] = board->value;
		board = board->next;
	}
}

void		write_number_to_register(uint8_t *reg, uint32_t nbr)
{
	reg[0] = (nbr >> 24);
	reg[1] = (uint8_t)(nbr >> 16);
	reg[2] = (uint8_t)(nbr >> 8);
	reg[3] = (uint8_t)(nbr >> 0);
}

void		write_reg_to_reg(uint8_t *dst_reg, uint8_t *src_reg)
{
	ft_memcpy(dst_reg, src_reg, 4);
}

uint32_t	read_from_board(t_board_node *board, uint8_t bytes)
{
	uint32_t	result;

	result = 0;
	while (bytes-- > 0)
	{
		result |= (uint32_t)board->value << (bytes * 8);
		board = board->next;
	}
	return (result);
}