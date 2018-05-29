/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 21:04:27 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/16 21:01:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wtoi.h"

/*
** gcc src/ft_wtoi.c -I inc/ libft.a
*/

static long long	get_rest(t_wtoi *w)
{
	int			i;

	i = -1;
	while (++i < 4)
	{
		if (ft_strnequ(w->s, w->bw[i], ft_strlen(w->bw[i])))
		{
			w->s += ft_strlen(w->bw[i]);
			return (w->bn[i]);
		}
	}
	return (1);
}

static long long	get_initial(t_wtoi *w, int i, int total)
{
	while (++i < 28)
	{
		if (ft_strnequ(w->s, w->w[i], ft_strlen(w->w[i])))
		{
			w->s += ft_strlen(w->w[i]);
			total += w->n[i];
			if (i > 9 && i < 18)
				total = get_initial(w, -1, total);
			if (i != 18)
			{
				if (ft_strnequ(w->s, "hundred", 7))
				{
					w->s += (ft_strnequ(w->s, "hundredand", 10)) ? 10 : 7;
					total = (total * 100) + get_initial(w, -1, 0);
				}
			}
			break ;
		}
	}
	return ((long long)total);
}

static void			move_to_next_legitimate_word(t_wtoi *w)
{
	int		i;

	while (*w->s)
	{
		i = -1;
		while (++i < 28)
		{
			if (ft_strnequ(w->s, w->w[i], ft_strlen(w->w[i])))
				return ;
		}
		w->s += 1;
	}
}

static void			instantiate_stuff(t_wtoi *w, char *num_string)
{
	int		i;

	w->w = ft_strsplits(NUMBER_WORDS, " ");
	w->bw = ft_strsplits("thousand million billion trillion", " ");
	i = -1;
	while (++i < 29)
	{
		if (i < 11)
			w->n[i] = i + 10;
		else if (i < 18)
			w->n[i] = (i - 8) * 10;
		else if (i < 28)
			w->n[i] = (i - 18);
		else if (i == 28)
			w->n[i] = -1;
	}
	i = -1;
	while (++i < 4)
		w->bn[i] = ft_powerof(1000, (long long)i + 1);
	w->section = (long long *)ft_memalloc(sizeof(long long) * 12);
	w->s = ft_strremove(num_string, " -");
	w->s_save = w->s;
}

long long			ft_wtoi(char *num)
{
	t_wtoi		w;
	int			i;

	instantiate_stuff(&w, num);
	i = -1;
	while (++i < 12 && *w.s)
	{
		w.final = 0;
		w.final += get_initial(&w, -1, 0);
		w.final *= get_rest(&w);
		w.section[i] = w.final;
		move_to_next_legitimate_word(&w);
	}
	w.final = w.section[0] + w.section[1] + w.section[2] + w.section[3] +
			w.section[4] + w.section[5] + w.section[6] + w.section[7] +
			w.section[8] + w.section[9] + w.section[10] + w.section[11];
	free(w.section);
	free(w.s_save);
	ft_arraydel(&w.w);
	ft_arraydel(&w.bw);
	return (w.final);
}
