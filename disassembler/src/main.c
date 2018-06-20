/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/06 13:35:15 by bpierce          ###   ########.fr       */
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

void	disassemble_contents(char *filename, uint8_t *c, size_t content_size)
{
	int		fd;
	char	fname_buff[ft_strlen(filename)];
	size_t	fname_len;

	fname_len = ft_strlen(filename) - 1;
	ft_strncpy(fname_buff + 1, filename, fname_len - 1);
	fname_buff[0] = '.';
	fname_buff[fname_len - 1] = 's';
	fname_buff[fname_len] = 0;
	fd = open(fname_buff, O_TRUNC | O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd == -1)
		DIS_ERR("Failed to open file to write to");
	g_filename = fname_buff;
	write_name_and_comment_to_file(fd, c);
	write_instructions_to_file(fd, &c[2192], content_size - 2192);
	close(fd);
	rename(fname_buff, fname_buff + 1);
}

void	write_name_and_comment_to_file(int fd, uint8_t *c)
{
	size_t	len;

	write(fd, ".name \"", 7);
	len = ft_strlen((char *)&c[4]);
	len = len > 128 ? 128 : len;
	write(fd, &c[4], len);
	write(fd, "\"\n.comment \"", 12);
	len = ft_strlen((char *)&c[140]);
	len = len > 2048 ? 2048 : 0;
	write(fd, &c[140], len);
	write(fd, "\"\n\n", 3);
}

void	write_instructions_to_file(int fd, uint8_t *c, size_t size)
{
	t_operation		op[17];
	uint16_t		i;

    ft_bzero(op, sizeof(t_operation) * 17);
	init_operations(op);
	i = 0;
	while (i < size)
	{
		if (c[i] == 0 || c[i] > 16)
			INSTR_ERR("A wild, invalid instruction has appeared");
		i += op[c[i]].instruct(fd, &op[c[i]], &c[i + 1]) + 1;
	}
}
