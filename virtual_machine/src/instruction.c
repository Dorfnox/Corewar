/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:45:10 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:45:12 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	First, initialize the instruction functions
*/

void       init_operations(t_corewar *core)
{
    core->op[0].instr = bad_;
    core->op[1].instr = live_;
    core->op[2].instr = ld_;
    core->op[3].instr = st_;
    core->op[4].instr = live_;
    core->op[5].instr = live_;
    core->op[6].instr = live_;
    core->op[7].instr = live_;
    core->op[8].instr = live_;
    core->op[9].instr = live_;
    core->op[10].instr = live_;
    core->op[11].instr = live_;
    core->op[12].instr = live_;
    core->op[13].instr = live_;
    core->op[14].instr = live_;
    core->op[15].instr = live_;
    core->op[16].instr = live_;
    init_wait_times(core);
}

void		init_wait_times(t_corewar *core)
{
    core->op[0].wait_time = 1;
    core->op[1].wait_time = 10;
    core->op[2].wait_time = 5;
    core->op[3].wait_time = 5;
    core->op[4].wait_time = 10;
    core->op[5].wait_time = 10;
    core->op[6].wait_time = 10;
    core->op[7].wait_time = 10;
    core->op[8].wait_time = 10;
    core->op[9].wait_time = 10;
    core->op[10].wait_time = 10;
    core->op[11].wait_time = 10;
    core->op[12].wait_time = 10;
    core->op[13].wait_time = 10;
    core->op[14].wait_time = 10;
    core->op[16].wait_time = 10;
}