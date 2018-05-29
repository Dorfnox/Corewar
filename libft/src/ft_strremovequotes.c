/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremovequotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:19:07 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/22 22:00:31 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strremovequotes(char *s)
{
	char	*new;
	char	buf[2];
	int		i;

	if (!s || !s[0] || (i = 0))
		return (NULL);
	if (!(new = ft_strnew(0)))
		return (NULL);
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && (++i))
			buf[0] = '\0';
		else if (s[i] == '\\' && (s[i + 1] == '\'' || s[i + 1] == '\"'))
		{
			buf[0] = s[i + 1];
			i += 2;
		}
		else if (++i)
			buf[0] = s[i - 1];
		if (!(new = ft_strfjoin(&new, buf)))
			return (NULL);
	}
	return (new);
}
