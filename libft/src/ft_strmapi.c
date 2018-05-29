/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:26:09 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 15:45:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		newstr = ft_strnew(ft_strlen((char *)s));
		if (newstr == NULL)
			return (NULL);
		while (s[i])
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
