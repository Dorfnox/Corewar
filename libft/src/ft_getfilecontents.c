/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfilecontents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:15:18 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/12 17:27:35 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	free_contents(int fd, uint8_t **contents)
{
	if (fd != -1)
		close(fd);
	free(*contents);
	*contents = NULL;
	return (0);
}

size_t			getfilecontents(char *filename, uint8_t **contents)
{
	uint8_t	buff[1024];
	int		fd;
	int		ret;
	size_t	total;

	if (!filename || !contents)
		return (0);
	*contents = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (free_contents(fd, contents));
	*contents = malloc(1);
	**contents = 0;
	total = 0;
	while ((ret = read(fd, buff, 1023)))
	{
		if (ret == -1)
			return (free_contents(fd, contents));
		buff[ret] = 0;
		if (!(*contents = ft_rememalloc(*contents, total, total + ret)))
			return (free_contents(fd, contents));
		ft_memcpy(&(*contents)[total], buff, ret);
		total += ret;
	}
	close(fd);
	return (total);
}

size_t			writetofile(char *filename, char *contents)
{
	size_t	total;
	int		ret;
	int		fd;

	if (!filename || !contents)
		return (0);
	if ((fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
		return (0);
	total = 0;
	if ((ret = write(fd, contents, ft_strlen(contents))) != -1)
		total = ret;
	close(fd);
	return (total);
}
