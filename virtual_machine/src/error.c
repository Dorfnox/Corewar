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

int		corewar_error(char *message, int return_value)
{
	if (message)
		write(2, message, ft_strlen(message));
	return (return_value);
}
