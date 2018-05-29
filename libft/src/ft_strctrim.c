/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:41:14 by aderby            #+#    #+#             */
/*   Updated: 2017/06/24 20:50:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	check_character(char const *s, const char c)
{
	unsigned int i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

char			*ft_strctrim(char const *s, const char c)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (s)
	{
		i = check_character(s, c);
		if (s[i] == '\0')
			return (ft_strnew(1));
		j = (unsigned int)ft_strlen(s) - 1;
		while (s[j] == c)
			j--;
		if (!(str = ft_strsub(s, i, (j - i + 1))))
			return (NULL);
	}
	else
		str = NULL;
	return (str);
}
