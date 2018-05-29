/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfrom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:41:14 by aderby            #+#    #+#             */
/*   Updated: 2018/01/11 19:58:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdupfrom(const char *s, const char c)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = 0;
	if (!s || !c)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] && s[i] != c)
		i++;
	if (!(str = ft_strsub(s, i, (len - i))))
		return (NULL);
	return (str);
}
