/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/29 13:23:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

# define PROCESS_STACK_LEN 1000

# define USAGE "usage: ./corewar\n"

typedef struct				s_player
{
	char					*name;
	char					*comment;
	uint64_t				last_live;	// The cycle the last live was called
	uint64_t				num_live;	// num of times live was called
}							t_player;

typedef struct				s_process
{
	t_player				*player;
	uint8_t					reg[REG_NUMBER + 1][4];
}							t_process;

typedef struct				s_corewar
{
	uint64_t				cycle;
	t_stack					process_stack[PROCESS_STACK_LEN];
	uint8_t					board[MEM_SIZE];
	t_player				player[MAX_PLAYERS];
	void					(*instr)(struct s_corewar *)[16];
}							t_corewar;

#endif
