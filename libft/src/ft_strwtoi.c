/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwtoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 19:40:55 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/16 21:03:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wtoi.h"

static char	*get_string_to_parse(char *s, int string_len)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * string_len);
	ft_strncpy(new, s, string_len);
	return (new);
}

static int	next_word_is_okay(char *s, int total, char **wordzies, char *last)
{
	int		i;

	i = -1;
	while (++i < 34)
	{
		if (ft_strnequ(&s[total], wordzies[i], ft_strlen(wordzies[i])))
		{
			if (i == 33)
				return (IS_AND_OKAY);
			else if (i >= 0 && i < 18)
				return (ARE_DOUBLES_OKAY);
			else if (i > 18 && i < 28)
				return (ARE_SINGLES_OKAY);
			else if (i == 28)
				return (IS_HUNDRED_OKAY);
			else if (i > 28 && i < 33)
				return (IS_THMIBITR_OKAY);
		}
	}
	return (0);
}

static int	nbr_str_len(char *s, int totallen, char **wordzies, int ignr_and)
{
	int		i;

	if (s)
	{
		i = -1;
		while (++i < 34)
		{
			if (ft_strnequ(&s[totallen], wordzies[i], ft_strlen(wordzies[i])))
			{
				if (ignr_and < 2 && ft_strnequ(&s[totallen], "and", 3))
					break ;
				ignr_and++;
				totallen += ft_strlen(wordzies[i]);
				if (next_word_is_okay(s, totallen + 1, wordzies, wordzies[i]))
					totallen = nbr_str_len(s, totallen + 1, wordzies, ignr_and);
			}
		}
	}
	return (totallen);
}

char		*ft_strwtoi(char *s)
{
	char		**wordzies;
	char		*str_to_parse;
	int			i;
	int			wordlen;
	char		*wtoi;

	if (s)
	{
		i = -1;
		wordzies = ft_strsplits(ALL_NUMBER_WORDS, " ");
		while (s[++i])
		{
			if ((wordlen = nbr_str_len(&s[i], 0, wordzies, 0)))
			{
				str_to_parse = get_string_to_parse(&s[i], wordlen);
				wtoi = ft_itoa((int)ft_wtoi(str_to_parse));
				ft_strcpy(&s[i], wtoi);
				ft_strcpy(&s[i + ft_strlen(wtoi)], &s[i + wordlen]);
				i += ft_strlen(wtoi);
				ft_strdeltwo(&str_to_parse, &wtoi);
			}
		}
		ft_arraydel(&wordzies);
	}
	return (s);
}
