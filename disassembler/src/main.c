/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 21:52:35 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

int		main(int ac, char **av)
{
	uint8_t		*contents;
	size_t		content_size;

	if (ac != 2)
		D_EXIT(DIS_USAGE);
	g_filename = NULL;
	filename_validation(av[1]);
	content_validation(av[1], &contents, &content_size);
	disassemble_contents(av[1], contents, content_size);
	return (0);
}

void	disassembler_exit(char *message)
{
	message ? ft_putendl(message) : 0;
	g_filename ? remove(g_filename) : 0;
	exit(1);
}

void	filename_validation(char *f)
{
	struct stat	path_stat;
	size_t		flen;

	if (!f || !f[0])
		FILE_ERR("Please provide a file");
	if (stat(f, &path_stat) == -1)
		FILE_ERR("does not exist. Please provide a good filename");
	if (!S_ISREG(path_stat.st_mode))
		FILE_ERR("is not of correct file type");
	if ((flen = ft_strlen(f)) < 5)
		FILE_ERR("is too short of a name to be a valid file. Must have .cor");
	if (!CHECK_EXTENSION)
		FILE_ERR("incorrect extension format. Must be a '.cor' file");
}

void	content_validation(char *f, uint8_t **c, size_t *content_size)
{
	*content_size = getfilecontents(f, c);
	*content_size == 0 ? FILE_ERR("is devoid of contents") : 0;
	*content_size > (2861) ? FILE_ERR("is too big to be a valid file") : 0;
	*content_size < (2181) ? FILE_ERR("is too small to be a valid file") : 0;
	if ((*c)[0] != 0 && (*c)[1] != 0xea && (*c)[2] != 0x83 && (*c)[3] != 0xf3)
		VAL_ERR("Corewar Magic is mysteriously missing");
}
