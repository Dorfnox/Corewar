/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:46:57 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/12 22:29:52 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char **s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !*s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	if (!(newstr = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)s2))))
	{
		ft_strdel(s1);
		return (NULL);
	}
	while ((*s1)[++i])
		newstr[i] = (*s1)[i];
	while (s2[j])
		newstr[i++] = s2[j++];
	ft_strdel(s1);
	return (newstr);
}
