/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:00:55 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/02 13:46:13 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	retrieve_data(t_corewar *core, char **argv)
{
	init_flag_queue(&core->flag_queue);
	while (!flag_handler(core, &argv))
	{
		if (ft_strstr(*argv, ".cor"))
		{
			if (core->player[0].player_num == 0)
				add_new_player(core, *argv, 1);
			else if (core->player[1].player_num == 0)
				add_new_player(core, *argv, 2);
			else if (core->player[2].player_num == 0)
				add_new_player(core, *argv, 3);
			else if (core->player[3].player_num == 0)
				add_new_player(core, *argv, 4);
			else
				add_new_player(core, *argv, 5);
			argv++;
		}
		else
			corewar_error(ft_str256(2, "Bad flag: ", *argv), 1);
	}
	clean_flag_queue(&core->flag_queue);
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
	if (n <= 0 && n > 4)
		corewar_error("Invalid player number", 1);
	player_corfile = *args;
	if (!player_corfile)
		corewar_error("Flag 'n' requires champion (.cor file)", 1);
	if (!ft_strstr(player_corfile, ".cor"))
		corewar_error("Flag 'n' requires champion (.cor file)", 1);
	add_new_player(core, *args, n);
	(*argv) = args;
	return (1);
}

unsigned int	flag_viz(t_corewar *core, char ***argv)
{
	if (core->flag.viz)
		corewar_error("You can't have two visualizers, silly!");
	return ((core->flag.viz = 1));
}

uint64_t		get_max_cycles(uint64_t init)
{
	if (init <= CYCLE_DELTA)
		return (0);
	return (init + get_max_cycles(init - CYCLE_DELTA));
}
