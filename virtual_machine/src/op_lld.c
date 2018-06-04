/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:57:22 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0d - LONG LOAD
**	- - - - - - - - - -
**	Loads a value into a register, but without a % IDX_MOD restriction
**
**	2 Parameters: 2nd must be a register (NOT THE PC)
**
**	NOTE: MODIFIES THE CARRY
*/

void		lld_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}
