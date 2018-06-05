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

void       init_operations(t_operation *op)
{
    op[0].instr = bad_;
    op[1].instr = live_;
    op[2].instr = ld_;
    op[3].instr = st_;
    op[4].instr = add_;
    op[5].instr = sub_;
    op[6].instr = and_;
    op[7].instr = or_;
    op[8].instr = xor_;
    op[9].instr = zjmp_;
    op[10].instr = ldi_;
    op[11].instr = sti_;
    op[12].instr = fork_;
    op[13].instr = lld_;
    op[14].instr = lldi_;
    op[15].instr = lfork_;
    op[16].instr = aff_;
    init_wait_times(op);
}

void		init_wait_times(t_operation *op)
{
    op[0].wait_time = 1;
    op[1].wait_time = 10;
    op[2].wait_time = 5;
    op[3].wait_time = 5;
    op[4].wait_time = 10;
    op[5].wait_time = 10;
    op[6].wait_time = 6;
    op[7].wait_time = 6;
    op[8].wait_time = 6;
    op[9].wait_time = 20;
    op[10].wait_time = 25;
    op[11].wait_time = 25;
    op[12].wait_time = 800;
    op[13].wait_time = 10;
    op[14].wait_time = 50;
    op[15].wait_time = 1000;
    op[16].wait_time = 2;
}