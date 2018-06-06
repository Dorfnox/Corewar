/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 22:36:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		first_(t_corewar *core, t_process *process)
{
	(void)core;
	(void)process;
}

void		bad_(t_corewar *core, t_process *process)
{
	(void)core;
	process->curr_pc = process->curr_pc->next;
}