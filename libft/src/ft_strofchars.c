/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:28:09 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/20 15:32:02 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strofchars(const char c, size_t num)
{
	char	*new;
	size_t	i;

	if (!(new = ft_strnew(num)))
		return (NULL);
	i = 0;
	while (i < num)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}
