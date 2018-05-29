/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayappend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:47:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/23 13:48:42 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Stores the given parameter in the given ***array
**	Will reallocate **save if things already exist in the deferenced array
**	The first time you send save, *save should be equal to null.
*/

unsigned int	ft_arrayappend(char ***save, char *param)
{
	char	**tmp;
	int		i;

	if (!param || !save)
		return (0);
	if ((tmp = *save))
	{
		i = -1;
		while (tmp[++i])
			;
		tmp = malloc(sizeof(char *) * (i + 2));
		ft_memcpy(tmp, *save, sizeof(char *) * i);
		tmp[i] = param;
		tmp[i + 1] = NULL;
	}
	else
	{
		tmp = malloc(sizeof(char *) * 2);
		tmp[0] = param;
		tmp[1] = NULL;
	}
	free(*save);
	*save = tmp;
	return (1);
}
