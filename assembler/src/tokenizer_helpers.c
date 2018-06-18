/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:14:13 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/17 16:58:52 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	remove_comment(char **s)
{
	int		pound_index;
	char	*tmp;

	pound_index = char_at(*s, '#', 0);
	if (pound_index != -1)
	{
		tmp = ft_strsub(*s, 0, pound_index);
		// free(s);
		*s = tmp;
	}
}

void	advance(t_input *line)
{
	line->index++;
	if (line->index > line->len - 1)
		line->current_char = '\0';
	else
		line->current_char = line->s[line->index];
}

void	skip_whitespaces(t_input *line)
{
	while (char_is_separator(line->current_char))
		advance(line);
}

void	remove_label_char(char **s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(*s);
	new_s = ft_strsub(*s, 0, len - 1);
	ft_strdel(s);
	*s = new_s;
}

int8_t	char_is_separator(char c)
{
	if (!c || c == SEPARATOR_CHAR || ft_iswhitespace(c))
		return (1);
	return (0);
}
