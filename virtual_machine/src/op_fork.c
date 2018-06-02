/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 14:56:31 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	0x0c - FORK
**	- - - - - - - - - -
**	Creates a new process for the player, and copies the current process's
**	registry into the new process
**
**	Not followed by parameter encoding byte
**
**	executes process at PC + index, with a % IDX_MOD restriction
**
*/

void		fork_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}
