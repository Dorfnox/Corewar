/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:27:31 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 18:59:03 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_token	*get_next_token(t_input *line)
{
	t_token	*new_token;

	new_token = (t_token *)ft_memalloc(sizeof(t_token));
	new_token->value = parse_value(line);
	get_token_type(new_token);
	return (new_token);
}

char	*parse_value(t_input *line)
{
	size_t	start;

	line->current_char = line->s[line->index];
	skip_separators(line);
	if (!line->current_char || !ft_isprint(line->current_char))
		return (NULL);
	else
	{
		start = line->index;
		while (line->current_char && !char_is_separator(line->current_char))
			advance(line);
		return (ft_strsub(line->s, start, line->index - start));
	}
}

void	get_token_type(t_token *token)
{
	uint8_t	subtype;

	subtype = 0;
	if (!token->value)
	{
		token->type = EMPTY;
		token->subtype = EMPTY;
		return ;
	}
	if ((subtype = check_if_header(token->value)))
		token->type = HEADER;
	else if (token_is_label(token->value))
	{
		remove_label_char(&token->value);
		token->type = LABEL;
		token->subtype = LABEL;
	}
	else if ((subtype = compare_to_ops(token->value)))
		token->type = OPERATION;
	else if ((subtype = compare_to_params(token->value)))
		token->type = PARAMETER;
	else
		token->type = NONE;
	token->subtype = subtype;
}
