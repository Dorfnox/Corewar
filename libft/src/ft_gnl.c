/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:47:59 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/07 21:12:34 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void		buffer_update(t_file *fptr, char **line)
{
	int		i;
	int		len;
	char	*tmp;

	if (fptr->line)
		free(fptr->line);
	fptr->line = ft_strdupuntil(fptr->str, '\n');
	i = ft_strccountto(fptr->str, '\n');
	len = ft_strlen(fptr->str);
	if (len > 0)
	{
		tmp = ft_strsub(fptr->str, i + 1, (len - i));
		free(fptr->str);
		fptr->str = tmp;
	}
	else
		ft_strdel(&fptr->str);
	*line = fptr->line;
}

static void		delete_current_file(t_file **myfile, t_file *fptr, char **line)
{
	t_file	*head;
	t_file	*tmp;

	head = *myfile;
	if (fptr == *myfile)
		head = (*myfile)->next;
	else if (fptr->next == NULL)
	{
		head = *myfile;
		while ((*myfile)->next != NULL)
			*myfile = (*myfile)->next;
	}
	else
	{
		while ((*myfile)->fd != fptr->fd)
		{
			tmp = *myfile;
			*myfile = (*myfile)->next;
		}
		tmp->next = (*myfile)->next;
	}
	ft_strdeltwo(&(*myfile)->str, &(*myfile)->line);
	free(*myfile);
	*myfile = head;
	*line = NULL;
}

static t_file	*add_new_file(const int fd)
{
	t_file		*tmp;

	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = ft_strnew(0);
	tmp->line = NULL;
	tmp->next = NULL;
	return (tmp);
}

static t_file	*move_to_file(const int fd, t_file **myfile)
{
	t_file	*fptr;

	fptr = *myfile;
	while (fptr)
	{
		if (fd == fptr->fd)
			return (fptr);
		fptr = fptr->next;
	}
	fptr = add_new_file(fd);
	fptr->next = *myfile;
	*myfile = fptr;
	return (fptr);
}

int				ft_gnl(const int fd, char **line)
{
	static t_file	*myfile;
	t_file			*fptr;
	char			buf[BUFF_SIZE + 1];
	int				res;

	if (fd < 0 || !(line) || read(fd, buf, 0) < 0)
		return (-1);
	fptr = move_to_file(fd, &myfile);
	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		fptr->str = ft_strfjoin(&fptr->str, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (res < BUFF_SIZE && !(ft_strlen(fptr->str)))
	{
		delete_current_file(&myfile, fptr, line);
		return (0);
	}
	buffer_update(fptr, line);
	return (1);
}
