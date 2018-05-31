/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:00:55 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/31 13:01:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	retrieve_data(t_corewar *core, char **argv)
{
	add_flag(&core->flag_queue, "-n", flag_n);
	add_flag(&core->flag_queue, "-dump", flag_dump);
	while (!flag_handler(core, &argv))
	{
		if (!add_player_file(core, *argv))
			corewar_error(ft_str256(3, "Bad Flag / File: '", *argv, "'"), 1);
	}
}

unsigned int	flag_dump(t_corewar *core, char ***argv)
{
	char **args;
	char *dump;

	args = ++(*argv);
	if (!*args)
		corewar_error("Flag '-dump' needs an argument (# of cycles)!!!", 1);
	dump = *args;
	if (!ft_isstrdigits(dump))
		corewar_error("Invalid cycle argument for option '-dump'", 1);
	core->flag.dump = 1;
	core->env.dump = ft_atoi(dump);
	core->env.max_cycles = get_max_cycles(CYCLE_TO_DIE);
	if (core->env.dump > core->env.max_cycles)
	{
		ft_pflite("TOOO MANY CYCLES. Max Cycles: %u\n", core->env.max_cycles);
		corewar_error(NULL, 1);
	}
	(*argv) = args;
	return (1);
}

unsigned int	flag_n(t_corewar *core, char ***argv)
{
	char	**args;
	int		n;
	char	*player_corfile;

	(void)core;
	args = ++(*argv);
	if (!*args)
		corewar_error("Flag 'n' needs an argument", 1);
	n = ft_atoi(*(args++));
	player_corfile = *args;
	if (n <= 0 && n > 4)
		corewar_error("Invalid player number", 1);
	if (!ft_strstr(player_corfile, ".cor"))
		corewar_error("Flag 'n' requires champion (.cor file)", 1);
	(*argv) = args;
	return 1; 
}

unsigned int	add_player_file(t_corewar *core, char *filename)
{
	(void)core;
	(void)filename;
	return (1);
}

uint64_t		get_max_cycles(uint64_t init)
{
	if (init <= CYCLE_DELTA)
		return 0;
	return (init + get_max_cycles(init - CYCLE_DELTA));
}