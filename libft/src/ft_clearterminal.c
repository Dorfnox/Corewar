/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearterminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:03:41 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/30 18:26:11 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clearterminal(int fd, int how_many_characters_you_want_to_clear)
{
	int		i;

	i = -1;
	if (how_many_characters_you_want_to_clear > 0)
		while (++i < how_many_characters_you_want_to_clear)
			write(fd, "\b \b", 3);
}
