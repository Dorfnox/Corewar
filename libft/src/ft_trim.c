/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:27:43 by bpierce           #+#    #+#             */
/*   Updated: 2018/02/05 22:54:12 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_trim:
**   - Returns a pointer to the SAME location in memory as 's' with
**     all leading and trailing whitespace trimmed.
**   - Eg: "  hey there martha!   " > "hey there martha!"
*/

char	*ft_trim(char *s)
{
	int		i;
	int		j;
	int		k;

	if (!s || !s[0] || (i = 0))
		return (s);
	while ((s[i] && ft_iswhitespace(s[i])) || ((j = i) && !j))
		if (!s[++i])
			return ((s[0] = '\0') ? s : s);
	k = 0;
	while (s[j] || !(k += 1))
	{
		k = !ft_iswhitespace(s[j]) ? j : k;
		++j;
	}
	if (!i && !(s[k] = '\0'))
		return (s);
	return ((ft_memcpy(s, &s[i], k - i) && (s[k - i] = '\0')) ? s : s);
}
