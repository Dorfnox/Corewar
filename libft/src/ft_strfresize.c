/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfresize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 13:25:07 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/14 13:36:13 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies contents of *s up to and/or past newsize.
** If given string = "abc" and newsize = 2 returns "ab\0"
** ^ Will lose ending data if incorrect newsize is given.
** If given string = "abc" and newsize = 5 returns "abc\0\0\0"
** Always includes that extra ending \0 for safety!
*/

char	*ft_strfresize(char **s, size_t newsize)
{
	char	*tmp;

	if (!(tmp = ft_strnew(newsize)))
		return (NULL);
	ft_strcpy(tmp, *s);
	ft_strdel(s);
	return (tmp);
}
