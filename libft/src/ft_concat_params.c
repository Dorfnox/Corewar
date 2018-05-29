/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:25:37 by bpierce           #+#    #+#             */
/*   Updated: 2018/02/24 23:27:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		len;
	int		len2;
	char	*s;

	if (argc < 2 || !argv)
		return (NULL);
	len = 0;
	i = 0;
	while (++i < argc)
		len += ft_strlen(argv[i]);
	s = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	len2 = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		ft_strncpy(&s[len2], argv[i], len);
		len2 += len;
	}
	s[len2] = '\0';
	return (s);
}
