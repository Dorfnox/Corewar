/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x09 - Z JUMP
**	- - - - - - - - - -
**	Takes an Index as a parameter and jumps to the current PC + index value
**
**	CANNOT be followed by a parameter encoding byte
**
**	WILL wait zjmp's wait time if parameter is valid or invalid
**
**	NOTE: MODIFIED BY THE CARRY
**	If carry == 1, make the jump.
**	If carry == null (0), ONLY wait
*/

void		zjmp_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}
