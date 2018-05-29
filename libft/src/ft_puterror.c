/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:29:47 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/26 15:08:48 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterror(const char *error_message, int return_value)
{
	if (error_message)
		ft_putendl(error_message);
	return (return_value);
}
