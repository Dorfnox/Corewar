/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:27:31 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/16 16:27:14 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	advance(t_input *line)
{
	line->index++;
	if (line->index > line->len - 1)
		line->current_char = '\0';
	else
		line->current_char = line->s[line->index];
}

char	*parse_value(t_input *line)
{
	size_t	start;
	
	line->current_char = line->s[line->index];
	skip_whitespaces(line);
	if (!line->current_char || !ft_isprint(line->current_char))
		return (NULL);
	else
	{
		start = line->index;
		while (!char_is_separator(line->current_char))
		{
			if (line->current_char == LABEL_CHAR)
			{
				advance(line);
				break ;
			}
			advance(line);
		}
		return (ft_strsub(line->s, start, line->index - start));
	}
}

void	get_token_type(t_token *token)
{
	uint8_t	subtype;
	
	// ft_putstr(token->value);
	if (!token->value)
	{
		token->type = EMPTY;
		token->subtype = EMPTY;
		return ;
	}
	if ((subtype = check_if_header(token->value)))
	{
		token->type = HEADER;
		token->subtype = subtype;
	}
	else if (token_is_label(token->value))
	{
		remove_label_char(&token->value);
		token->type = LABEL;
		token->subtype = LABEL;
	}
	else if ((subtype = compare_to_ops(token->value)))
	{
		token->type = OPERATION;
		token->subtype = subtype;
	}
	else if ((subtype = compare_to_params(token->value)))
	{
		token->type = PARAMETER;
		token->subtype = subtype;
	}
	else
	{
		token->type = NONE;
		token->subtype = NONE;
	}
	// ft_putnbr(token->type);
}

t_token	*get_next_token(t_input *line)
{
	t_token		*new_token;

	new_token = (t_token *)ft_memalloc(sizeof(t_token));
	new_token->value = parse_value(line);
	// ft_putstr(new_token.value);
	get_token_type(new_token);
	// ft_putnbr(new_token.type);
	return (new_token);
}


