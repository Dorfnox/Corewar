/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:54:10 by bpierce           #+#    #+#             */
/*   Updated: 2018/04/05 15:05:35 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}

void	ft_strnclr(char *s, size_t len)
{
	size_t	i;

	if (s && *s && len != 0 && !(i = 0))
		while (s[i] && i < len)
			s[i++] = '\0';
}
