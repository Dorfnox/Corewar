/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:19:30 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/23 13:54:43 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

uint8_t	len_tokens(uint8_t op)
{
	static uint8_t	lens[17];

	lens[0] = 0;
	lens[LIVE] = 1;
	lens[LD] = 2;
	lens[ST] = 2;
	lens[ADD] = 3;
	lens[SUB] = 3;
	lens[AND] = 3;
	lens[OR] = 3;
	lens[XOR] = 3;
	lens[ZJMP] = 1;
	lens[LDI] = 3;
	lens[STI] = 3;
	lens[FORK] = 1;
	lens[LLD] = 2;
	lens[LLDI] = 3;
	lens[LFORK] = 1;
	lens[AFF] = 1;
	return (lens[op]);
}
