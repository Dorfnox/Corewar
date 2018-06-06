/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x05 - SUBTRACT
**	- - - - - - - - - -
**	Takes 3 registers as parameters. Subtracts a - b, stores result into c reg
*/

void		sub_(t_corewar *core, t_process *process)
{
	uint32_t	subtractive_result;

	(void)core;
	subtractive_result = 0;
	DB("subtracting");
	if (!parse_encoding_byte(process))
		return ; // Do we just treat the next argument as an operation?
	if (EB0 != REGISTER || EB1 != REGISTER || EB2 != REGISTER)
		return ;
	if (!parse_arguments(process))
		return ;
	subtractive_result = smash_bytes(process->reg[process->args[0][0]]);
	subtractive_result -= smash_bytes(process->reg[process->args[1][0]]);
	ft_printf("subtractive result: %.8x\n", subtractive_result);
	process->reg[process->args[2][0]][0] = (uint8_t)(subtractive_result >> 24);
	process->reg[process->args[2][0]][1] = (uint8_t)(subtractive_result >> 16);
	process->reg[process->args[2][0]][2] = (uint8_t)(subtractive_result >> 8);
	process->reg[process->args[2][0]][3] = (uint8_t)(subtractive_result >> 0);
}
