/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:29 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0e - LONG LOAD INDEX
**	- - - - - - - - - -
**	Loads an indexed value into a register, WITHOUT the % IDX_MOD restriction
**
**	Takes 3 parameters (2 indexes, 1 registry), adds first two, and puts result
**	into the third-parameter's register
**
**	REG_SIZE bytes are read at the sum of the first two indexes, then loaded
**	into whatever register is in the third parameter
**
**	NOTE: MODIFIES THE CARRY
*/

void		lldi_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}
