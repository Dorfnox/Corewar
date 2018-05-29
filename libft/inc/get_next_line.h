/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 21:28:55 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/28 13:50:18 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1

typedef struct		s_file
{
	int				fd;
	char			*str;
	char			*line;
	struct s_file	*next;
	unsigned short	i:1;
}					t_file;

int					ft_gnl(const int fd, char **line);
void				ft_gnlfreeall(t_file **myfile);

#endif
