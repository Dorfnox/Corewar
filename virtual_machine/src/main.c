/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/31 12:54:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_board(t_corewar *core)
{
	uint8_t tp;
	uint8_t p;
	char *instructions;
	unsigned int content_size;

	tp = core->env.num_players;
	ft_putnbr(tp);
	ft_putchar('\n');
	p = 0;
	while (++p < 5)
	{
		if (core->player[p - 1].player_num)
		{
			content_size = core->player[p - 1].header.prog_size;
			instructions = core->player[p - 1].header.instructions;
			writeinstructions_to_map(((p - 1) * (4096 / tp)), (uint8_t *)instructions, core->board, content_size - INSTR);
		}
	}
}

int		main(int argc, char **argv)
{
	t_corewar	core;

	if (argc == 1)
		corewar_error(USAGE, 1);
	ft_bzero(&core, sizeof(t_corewar));
	retrieve_data(&core, ++argv);
	init_board(&core);
//	init_player_processes(&core);
	int i = 0;
	while (i < 4)
	{
		ft_pflite("player: %u, name: %s\n", i + 1, core.player[i].header.prog_name);
		ft_pflite("player: %u, comm: %s\n", i + 1, core.player[i].header.comment);
		i++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i == 1365 || i == 2730)
			printf("XX");
		else
			printf("%0.2x", core.board[i]);
		printf(" ");
		if (!(i % 63) && i >= 63)
			printf("\n");
		i++;
	}
//	validation();
//	ft_memcpy
	return (0);
}
