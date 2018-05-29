/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrayfromstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:07:38 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/30 20:35:10 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	good_string(char *s)
{
	int		int_flag;
	int		i;

	int_flag = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ' && !ft_isdigit(s[i]))
			return (0);
		if (ft_isdigit(s[i]))
			int_flag = 1;
	}
	return (int_flag);
}

int			*ft_intarrayfromstr(char *str_of_ints)
{
	char	**tmp;
	int		i;
	int		*array;

	if (!str_of_ints || ft_strlen(str_of_ints) < 1)
		return (NULL);
	if (!good_string(str_of_ints))
		return (NULL);
	tmp = ft_strsplit(str_of_ints, ' ');
	i = 0;
	while (tmp[i])
		i++;
	if (!(array = (int *)ft_memalloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while (tmp[++i] || (i = -1) == 0)
		array[i] = ft_atoi(tmp[i]);
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (array);
}
