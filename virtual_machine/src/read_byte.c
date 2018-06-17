/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:47:52 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/13 21:48:04 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
