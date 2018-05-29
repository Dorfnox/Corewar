/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfremalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:25:38 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/14 13:19:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If given string such as "Hello\n\0\0\0\0\0\0\0\0"
** will return new string "Hello\n" and free space taken up by \0's
*/

char	*ft_strfremalloc(char **s)
{
	char	*new;

	if (!(new = ft_strdup(*s)))
		return (NULL);
	free(*s);
	*s = NULL;
	return (new);
}
