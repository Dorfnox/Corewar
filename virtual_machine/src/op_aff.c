/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:45:09 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x10 - AFF...?
**	- - - - - - - - - -
**	Displays a character on the standard output % 256
**
**	Takes a parameter encoding byte
*/

void		aff_(t_corewar *core, t_process *process)
{
	(void)core;
	if (!parse_encoding_byte(process) ||
		EB0 != REGISTER || EB1 || EB2)
	{
		move_pc_by_encoding_byte(process, 0, 1);
		return ;
	}
	if (!parse_arguments(process, 0))
		return ;
	ft_putchar((int)smash_bytes(process->args[0]) % 256);
}
