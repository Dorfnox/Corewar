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
    op[0].instruct = bad_;
    op[1].instruct = live_;
    op[2].instruct = ld_;
    op[3].instruct = st_;
    op[4].instruct = add_;
    op[5].instruct = sub_;
    op[6].instruct = and_;
    op[7].instruct = or_;
    op[8].instruct = xor_;
    op[9].instruct = zjmp_;
    op[10].instruct = ldi_;
    op[11].instruct = sti_;
    op[12].instruct = fork_;
    op[13].instruct = lld_;
    op[14].instruct = lldi_;
    op[15].instruct = lfork_;
    op[16].instruct = aff_;
    op[17].instruct = first_;
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
    op[17].wait_time = 0;
    init_instruction_names(op);
}

void        init_instruction_names(t_operation *op)
{
    ft_memcpy(&op[0].name, "bad", 3);
    ft_memcpy(&op[1].name, "live", 4);
    ft_memcpy(&op[2].name, "ld", 2);
    ft_memcpy(&op[3].name, "st", 2);
    ft_memcpy(&op[4].name, "add", 3);
    ft_memcpy(&op[5].name, "sub", 3);
    ft_memcpy(&op[6].name, "and", 3);
    ft_memcpy(&op[7].name, "or", 2);
    ft_memcpy(&op[8].name, "xor", 3);
    ft_memcpy(&op[9].name, "zjmp", 4);
    ft_memcpy(&op[10].name, "ldi", 3);
    ft_memcpy(&op[11].name, "sti", 3);
    ft_memcpy(&op[12].name, "fork", 4);
    ft_memcpy(&op[13].name, "lld", 3);
    ft_memcpy(&op[14].name, "lldi", 4);
    ft_memcpy(&op[15].name, "lfork", 5);
    ft_memcpy(&op[16].name, "aff", 3);
    ft_memcpy(&op[17].name, "first", 5);
}
