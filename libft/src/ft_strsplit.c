/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:04:22 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/07 20:27:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_words(const char *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	if (s[0] && c == '\0')
		return (1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		while (s[i] == c)
			++i;
	}
	return (count);
}

static char	**set_initial_strsplit(const char *s, char c, int *num, int *i)
{
	char	**new;

	if (!s || !(*num = n_words(s, c)))
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * (*num + 1))))
		return (NULL);
	*i = 0;
	return (new);
}

static void	*free_strsplit(char **new, int k)
{
	while (k > -1)
	{
		free(new[k]);
		new[k--] = NULL;
	}
	free(new);
	return (NULL);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**new;
	int		num_of_words;

	if (!(new = set_initial_strsplit(s, c, &num_of_words, &i)))
		return (NULL);
	k = -1;
	while (s[i] && !(j = 0))
	{
		while ((s[i] && s[i] == c) || (s[i + j] && s[i + j] != c))
			s[i] == c ? ++i : ++j;
		if (j)
		{
			if (!(new[++k] = (char *)malloc(sizeof(char) * (j + 1))))
				return (free_strsplit(new, k));
			new[k][j] = '\0';
		}
		else
			new[++k] = NULL;
		ft_strncpy(new[k], &s[i], j);
		i += j;
	}
	return (!(new[n_words(s, c)] = NULL) ? new : new);
}
