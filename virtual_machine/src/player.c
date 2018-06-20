/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:43:23 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 01:23:40 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#define PLAYA core->player[p_num - 1]

void			add_new_player(t_corewar *core, char *filename, uint8_t p_num)
{
	uint8_t		*contents;
	size_t		content_size;

	if (++core->env.num_players == 5 || p_num == 5)
		corewar_error("Too many players", 1);
	if (core->player[p_num - 1].player_num)
	{
		ft_pflite("%s\tPlayer number assigned for more than one player\n"
				, CSEM);
		ft_pflite("\tPlayer %u: Player '%s' and Player '%s'\n",
			p_num, PLAYA.filename, filename);
		corewar_error(NULL, 1);
	}
	content_size = import_player_file(filename, &contents);
	ft_memcpy(PLAYA.header.prog_name, &contents[4], PROG_NAME_LENGTH);
	ft_memcpy(PLAYA.header.comment, &contents[140], COMMENT_LENGTH);
	ft_memcpy(PLAYA.header.instructions, &contents[INSTR + 16],
			content_size - INSTR);
	PLAYA.header.prog_size = content_size;
	PLAYA.instruction_size = content_size - (INSTR + 16);
	PLAYA.player_num = p_num;
	PLAYA.num_of_processes = 1;
	PLAYA.filename = filename;
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
	content_size = getfilecontents(filename, contents);
	if (!content_size)
	{
		ft_str256(3, "Failed to gather file's contents: '", filename, "'");
		corewar_error(ft_str256(0), 1);
	}
	if ((content_size < INSTR) || (content_size > INSTR + CHAMP_MAX_SIZE))
	{
		ft_str256(3, "The file '", filename, "' is of incorrect size");
		corewar_error(ft_str256(0), 1);
	}
	return (content_size);
}
