/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:12:34 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/13 16:55:30 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(s) - 1;
	if (len == 0)
		return (s);
	while (i < len - i)
	{
		tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
		i++;
	}
	return (s);
}
