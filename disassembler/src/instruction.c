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

#include "disassembler.h"

void       init_operations(t_operation *op)
{
    op[1].instruct = live_;
    // op[2].instruct = ld_;
    op[3].instruct = st_;
    op[4].instruct = math_;
    op[5].instruct = math_;
    op[6].instruct = math_;
    op[7].instruct = math_;
    op[8].instruct = math_;
    op[9].instruct = zjmp_;
    // op[10].instruct = ldi_;
    // op[11].instruct = sti_;
    op[12].instruct = fork_;
    // op[13].instruct = lld_;
    // op[14].instruct = lldi_;
    op[15].instruct = lfork_;
    // op[16].instruct = aff_;
    init_instruction_names(op);
}

void        init_instruction_names(t_operation *op)
{
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
}
