/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/29 13:23:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint64_t		recursive(uint64_t init)
{
	if (init <= CYCLE_DELTA)
		return 0;
	return (init + recursive(init - CYCLE_DELTA));
}

unsigned int	flag_n(t_corewar *core, char ***argv)
{
	(void)core;
	char **args;
	int n;
	char *player_corfile;

	args = ++(*argv);
	n = ft_atoi(*(args++));
	player_corfile = *args;
	if (n <= 0 && n > 4)
		corewar_error("Invalid player number", 1);
	if (!ft_strstr(player_corfile, ".cor"))
		corewar_error("Flag 'n' requires champion (.cor file)", 1);
	(*argv) = args;
	return 1; 
}

unsigned int	flag_dump(t_corewar *core, char ***argv)
{
	char **args;
	char *dump;

	args = ++(*argv);
	dump = *args;
	if (!ft_isstrdigits(dump))
		corewar_error("Invalid character in cycle argument for option '-dump'", 1);
	core->flag_dump = 1;
	core->dump = ft_atoi(dump);
	if (core->dump > recursive(CYCLE_TO_DIE))
		corewar_error("TOOO MANY CYCLES", 1);
	(*argv) = args;
	return 1;
}

unsigned int	add_player_file(t_corewar *core, char *filename)
{
	
}

void	retrievedata(t_corewar *core, char **argv)
{
	add_flag(&core->flag_queue, "-n", flag_n);
	add_flag(&core->flag_queue, "-dump", flag_dump);
	while (!flag_handler(core, &argv))
	{
		if (!add_player_file(core, *argv))
			corewar_error(ft_str256(3, "Bad Flag / File: '", *argv, "'\n"), 1);
	}
}

int		main(int argc, char **argv)
{
	t_corewar	core;

	if (argc == 1)
		corewar_error(USAGE, 1);
	ft_bzero(&core, sizeof(t_corewar));
	++argv;
	retrievedata(&core, argv);
//	validation();
//	ft_memcpy
	return (0);
}
