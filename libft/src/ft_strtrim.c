/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:16:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:44:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (is_whitespace(s[len - 1]) == 1)
		len--;
	i = -1;
	while (is_whitespace(s[++i]) == 1)
		len--;
	if (len <= 0)
		len = 0;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		newstr[i] = *s++;
	newstr[i] = '\0';
	return (newstr);
}
