/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:26:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 18:53:36 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_token	*get_params(t_asm *assembler, t_input *line, uint8_t len_tokens)
{
	t_token *tokens;
	t_token	*tmp;
	int8_t	i;

	i = -1;
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * len_tokens);
	while (++i < len_tokens)
	{
		tmp = get_next_token(line);
		tokens[i] = *tmp;
		if (tokens[i].type != PARAMETER)
			syntax_error_with_token(assembler, line,
									PARAM_ERROR_ABSENT, tokens[i].value);
		// free(tmp->value);
        free(tmp);
	}
	return (tokens);
}

uint8_t	create_ecb(t_token *tokens, uint8_t len_tokens)
{
	uint8_t	ecb;
	int8_t	i;

	i = -1;
	ecb = 0;
	while (++i < 3)
	{
		ecb += (i < len_tokens) ? tokens[i].subtype : 0;
		ecb <<= 2;
	}
	return (ecb);
}
