/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:22:40 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/30 16:28:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Writes an error message to the stderr and returns the given return_value
*/

void		corewar_error(char *message, int return_value)
{
	ft_putstr(CSEM);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	else
		ft_putstr("Error\n");
	exit(return_value);
}
