/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:04:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/11 19:39:56 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_strsplit_char(char c, char *chrctrs)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(chrctrs);
	while (chrctrs[i] != c && chrctrs[i])
		i++;
	return (len - i);
}

static int	n_words(const char *s, char *c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(is_strsplit_char(s[i], c)))
		{
			count++;
			while (!(is_strsplit_char(s[i], c)) && s[i])
				i++;
		}
		while (is_strsplit_char(s[i], c) && s[i])
			i++;
	}
	return (count);
}

static int	set_initial_strsplit(char ***new, const char *s, char *c, int *i)
{
	if (!s || !(n_words(s, c)))
		return (0);
	if (!(*new = (char **)malloc(sizeof(char *) * (n_words(s, c) + 1))))
		return (0);
	*i = 0;
	return (1);
}

static void	*free_strsplit(char **new, int k)
{
	while (k > -1)
		free(new[k--]);
	free(new);
	return (NULL);
}

char		**ft_strsplits(const char *s, char *c)
{
	int		i;
	int		j;
	int		k;
	char	**new;

	if (!(set_initial_strsplit(&new, s, c, &i)) || !(k = -1))
		return (NULL);
	while (s[i] && !(j = 0))
	{
		while ((s[i] && is_strsplit_char(s[i], c)) ||
				(s[i + j] && !is_strsplit_char(s[i + j], c)))
			is_strsplit_char(s[i], c) ? ++i : ++j;
		if (j)
		{
			if (!(new[++k] = (char *)malloc(sizeof(char) * (j + 1))))
				return (free_strsplit(new, k));
		}
		else
			new[++k] = NULL;
		ft_strncpy(new[k], &s[i], j);
		i += j;
	}
	return (!(new[n_words(s, c)] = NULL) ? new : new);
}
