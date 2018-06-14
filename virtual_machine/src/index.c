/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:46:18 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/13 21:47:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint16_t 	get_index_unchained(uint16_t pc, uint8_t idx_byte1, uint8_t idx_byte2)
{
	uint16_t index;

	index = (uint16_t)idx_byte1 << 8;
	index |= (uint16_t)idx_byte2;
	if (idx_byte1 >> 7)
	{
		index = ~index + 1;
		return (((MEM_SIZE - pc - 1) + index) % MEM_SIZE);
	}
	return ((pc + index) % MEM_SIZE);
}

/*
**	Use the normal return for 'positive' indexes on the node_addresses array
**	Use the idx_byte1 >> 7 return for 'negative' indexes on the
**	node_addresses_rev array
*/

uint16_t 	get_index(uint16_t pc, uint8_t idx_byte1, uint8_t idx_byte2)
{
	uint16_t index;

	index = (uint16_t)idx_byte1 << 8;
	index |= (uint16_t)idx_byte2;
	if ((idx_byte1 >> 7))
	{
		index = ~index + 1;
		index %= IDX_MOD;
		return (((MEM_SIZE - pc - 1) + index) % MEM_SIZE);
	}
	return ((pc + (index % IDX_MOD)) % MEM_SIZE);
}
