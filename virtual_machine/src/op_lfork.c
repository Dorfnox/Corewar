/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 15:38:56 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0f - LONG FORK
**	- - - - - - - - - -
**	Creates a new process for the player, and copies the current process's
**	registry into the new process
**
**	Not followed by parameter encoding byte
**
**	executes process at PC + index, without the % IDX_MOD restriction
**
**	NOTE: MODIFIES THE CARRY
*/

void		lfork_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}
