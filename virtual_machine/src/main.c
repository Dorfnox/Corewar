/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:46:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_board(t_corewar *core, t_process *p)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (p->curr_pc->index == i)
			printf("\033[42;92m");
		else
			printf("\033[0m");
		printf("%0.2x", core->board->value);
		printf(" ");
		if (!(i % 63) && i >= 63)
			printf("\n");
		core->board = core->board->next;
		i++;
	}
	write(1, "\n\n", 2);
}

int		main(int argc, char **argv)
{
	t_corewar	core;

	if (argc == 1)
		corewar_error(USAGE, 1);
	ft_bzero(&core, sizeof(t_corewar));
	retrieve_data(&core, ++argv);
	init_board(&core);
	init_operations(core.op);
	loop(&core);
	int i = 0;
	while (i < 4)
	{
		ft_pflite("player: %u, name: %s\n", i + 1, core.player[i].header.prog_name);
		ft_pflite("player: %u, comm: %s\n", i + 1, core.player[i].header.comment);
		i++;
	}
	i = 0;
	// print_board(&core);
	return (0);
}
