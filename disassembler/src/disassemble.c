/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:51:38 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 21:52:20 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

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
	len = len > 2048 ? 2048 : len;
	write(fd, (char *)&c[140], len);
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
