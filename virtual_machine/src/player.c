/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:43:23 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/31 15:43:36 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			add_new_player(t_corewar *core, char *filename, uint8_t p_num)
{
	uint8_t		*contents;
	size_t		content_size;

	DB(filename);
	if (++core->env.num_players == 5)
		corewar_error("Too many players", 1);
	if (core->player[p_num - 1].player_num)
	{
		ft_pflite("%s\tPlayer number assigned for more than one player\n", CSEM);
		ft_pflite("\tPlayer %u: Player '%s' and Player '%s'\n",
			p_num, core->player[p_num - 1].filename, filename);
		corewar_error(NULL, 1);
	}
	content_size = import_player_file(filename, &contents);
	ft_memcpy(core->player[p_num - 1].header.prog_name, &contents[4], PROG_NAME_LENGTH);
/*	int i = 0;
	printf("\n");
	while (i < 128)
		printf("%.2x", contents[i++]);
	printf("\n");
	while (i < INSTR)
		printf("%.2x", contents[i++]);
	printf("\n");*/
	ft_memcpy(core->player[p_num - 1].header.comment, &contents[128 + 12], COMMENT_LENGTH);
	writeinstructions_to_map(((p_num - 1) * (4096 / 4)), &contents[INSTR + 16], core->board, content_size - INSTR);
	core->player[p_num - 1].player_num = p_num;
	core->player[p_num - 1].filename = filename;
}

/*
**	Does general validation of the file and stores the contents into **contents
*/

size_t			import_player_file(char *filename, uint8_t **contents)
{
	struct stat	path_stat;
	size_t		content_size;

	if (!filename)
		corewar_error("Corewar needs a proper filename", 1);
	stat(filename, &path_stat);
	if (!S_ISREG(path_stat.st_mode))
		corewar_error("Invalid file type. Please use a [.cor] file", 1);
	content_size = getfilecontents(filename, (char**)contents);
	if (!content_size)
	{
		ft_str256(3, "Failed to gather file's contents: '", filename ,"'");
		corewar_error(ft_str256(0), 1);
	}
	if (content_size < INSTR ||	content_size > INSTR + CHAMP_MAX_SIZE)
	{
		ft_str256(3, "The file '", filename, "' is of incorrect size");
		corewar_error(ft_str256(0), 1);
	}
	return content_size;
}

/*
**	Creates processes and adds them to stack[board's first byte 'wait' value]
**	Must be called after the board has been set.
*/


void			init_player_processes(t_corewar *core)
{
	t_process	*process;
	uint32_t	pc_location;
	uint8_t		i;

	i = 0;
	pc_location = 0;
	while (i < MAX_PLAYERS)
	{
		if (core->player[i].player_num)
		{
			process = new_process(&core->player[i], pc_location);
			push(&core->process_stack[0], process);
		}
		++i;
		pc_location += (MEM_SIZE / 4);
	}
}