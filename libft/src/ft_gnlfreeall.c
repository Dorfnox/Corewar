/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlfreeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 22:44:03 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/10 14:46:00 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	ft_gnlfreeall(t_file **myfile)
{
	t_file	*terminator;

	terminator = *myfile;
	while ((*myfile)->next)
	{
		terminator = (*myfile)->next;
		ft_strdel(&(*myfile)->str);
		free(*myfile);
		(*myfile) = terminator;
	}
	ft_strdel(&(*myfile)->str);
	free(*myfile);
	(*myfile) = NULL;
}
