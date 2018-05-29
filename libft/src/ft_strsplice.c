/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:52:29 by bpierce           #+#    #+#             */
/*   Updated: 2018/04/06 18:04:08 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strsplice:
**	- Takes a splice_str and splices it into the splice_loc of splice
**	- Returns a newly-malloc'd str
**	- When splice_loc is not defined within splice, output is undefined
*/

char		*ft_strsplice(char *splice, int index, char *splice_str)
{
	char	*new;
	int		i;
	int		tot_len;

	if (!splice || !splice_str || !(i = -1))
		return (NULL);
	tot_len = ft_strlen(splice);
	index = index > tot_len ? tot_len : index;
	if (!(tot_len += ft_strlen(splice_str)))
		return (NULL);
	if (!(new = malloc(sizeof(char) * (tot_len + 1))))
		return (NULL);
	while (++i != index)
		new[i] = *(splice++);
	while (*splice_str)
		new[i++] = *(splice_str++);
	while (*splice)
		new[i++] = *(splice++);
	return ((new[i] = '\0') ? new : new);
}

static int	free_splice(char **splice)
{
	ft_strdel(splice);
	return (1);
}

char		*ft_strfsplice(char **splice, int index, char *splice_str)
{
	char	*new;
	char	*tmp;
	int		i;
	int		tot_len;

	if (!splice || !*splice || !splice_str || !(i = -1))
		return (NULL);
	tmp = *splice;
	tot_len = ft_strlen(tmp);
	index = index > tot_len ? tot_len : index;
	if (!(tot_len += ft_strlen(splice_str)) && free_splice(splice))
		return (NULL);
	if (!(new = malloc(sizeof(char) * (tot_len + 1))) && free_splice(splice))
		return (NULL);
	while (++i != index)
		new[i] = *(tmp++);
	while (*splice_str)
		new[i++] = *(splice_str++);
	while (*tmp)
		new[i++] = *(tmp++);
	ft_strdel(splice);
	return ((new[i] = '\0') ? new : new);
}
