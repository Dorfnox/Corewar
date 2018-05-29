/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfremovequotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:19:07 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/22 22:07:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfremovequotes(char **t)
{
	char	*new;
	char	*s;
	char	buf[2];
	int		i;

	if (!t || !(s = *t))
		return (NULL);
	if (!s || !s[0] || (i = 0))
		return (NULL);
	if (!(new = ft_strnew(0)))
		return (NULL);
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && (++i))
			buf[0] = '\0';
		else if ((s[i] == '\\' && (s[i + 1] == '\'' || s[i + 1] == '\"')) &&
				(i += 2))
			buf[0] = s[i - 1];
		else if (++i)
			buf[0] = s[i - 1];
		if (!(new = ft_strfjoin(&new, buf)))
			return (NULL);
	}
	ft_strdel(t);
	return (new);
}
