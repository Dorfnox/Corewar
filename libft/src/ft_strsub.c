/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:22:24 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/06 17:02:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	while (s[start] && i < len)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
