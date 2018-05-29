/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:26:09 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/26 15:56:04 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		if (!(newstr = ft_strnew(ft_strlen((char *)s))))
			return (NULL);
		while (s[i])
		{
			newstr[i] = f(s[i]);
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
