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
	init_environment(&core);
	retrieve_data(&core, ++argv);
	init_ncurses(&core);
	init_board(&core);
	init_operations(core.op);
	core.flag.viz ? loop_viz(&core) : loop(&core);
	terminate_ncurses(&core);
	return (0);
}
