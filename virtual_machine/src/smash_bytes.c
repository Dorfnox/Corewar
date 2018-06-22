/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:42:42 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 17:42:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Returns a uint32_t of the number stored in an array 0, 1, 2, 3
*/

uint32_t	smash_bytes(uint8_t *reg)
{
	uint32_t	result;

	result = 0;
	result |= ((uint32_t)reg[0]) << 24;
	result |= ((uint32_t)reg[1]) << 16;
	result |= ((uint32_t)reg[2]) << 8;
	result |= ((uint32_t)reg[3]) << 0;
	return (result);
}

uint8_t		*unsmash_bytes(uint32_t nbr)
{
	static uint8_t	unsmashme[4];

	unsmashme[0] = (nbr >> 24);
	unsmashme[1] = (nbr >> 16) & 0xFF;
	unsmashme[2] = (nbr >> 8) & 0xFF;
	unsmashme[3] = (nbr >> 0) & 0xFF;
	return (unsmashme);
}
