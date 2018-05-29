/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindnreplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:40:58 by aderby            #+#    #+#             */
/*   Updated: 2017/06/24 17:49:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfindnreplace(char *s, char f, char r, int n)
{
	char	*ptr;
	char	*ptrhold;

	ptr = ft_strdup(s);
	ptrhold = ptr;
	while (*ptr || n-- > 0)
	{
		if (*ptr == f)
			*ptr = r;
		ptr++;
	}
	ptr = ptrhold;
	return (ptr);
}
