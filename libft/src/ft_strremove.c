/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:38:35 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/20 15:58:06 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns newly malloc'd string with all characters given removed
** An iterative option is also available that does not remalloc, but requires
** an editable (malloc'd) string to transform
*/

static int	str_has_char(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char		*ft_strremove(char *s, char *rem_chars)
{
	int		i;
	int		flag;

	if (!s)
		return (NULL);
	if (!rem_chars || !rem_chars[0])
		return (s);
	i = 0;
	flag = 0;
	while (s[i + flag])
	{
		while (s[i + flag] && str_has_char(rem_chars, s[i + flag]))
			++flag;
		if ((s[i] = s[i + flag]))
			++i;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strremovenobs(char *s, char *rem_chars)
{
	int		i;
	int		flag;

	if (!s)
		return (NULL);
	if (!rem_chars || !rem_chars[0])
		return (s);
	i = 0;
	flag = 0;
	while (s[i + flag])
	{
		if (s[i + flag] == '\\')
			++flag;
		else
			while (s[i + flag] && str_has_char(rem_chars, s[i + flag]))
				++flag;
		if ((s[i] = s[i + flag]))
			++i;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strcremove(char *s, char remove_char)
{
	int		i;
	int		flag;

	if (!s)
		return (NULL);
	if (!remove_char)
		return (s);
	i = 0;
	flag = 0;
	while (s[i + flag])
	{
		while (s[i + flag] && s[i + flag] == remove_char)
			++flag;
		if ((s[i] = s[i + flag]))
			++i;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strcremovenobs(char *s, char remove_char)
{
	int		i;
	int		flag;

	if (!s)
		return (NULL);
	if (!remove_char)
		return (s);
	i = 0;
	flag = 0;
	while (s[i + flag])
	{
		if (s[i + flag] == '\\')
			++flag;
		else
			while (s[i + flag] && s[i + flag] == remove_char)
				++flag;
		if ((s[i] = s[i + flag]))
			++i;
	}
	s[i] = '\0';
	return (s);
}
