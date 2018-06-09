/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:26:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/08 00:44:25 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_token		*get_params(t_input *line, uint8_t len_tokens)
{
	t_token *tokens;
	int8_t	i;

	i = -1;
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * len_tokens);
	while (++i < len_tokens)
	{
		tokens[i] = get_next_token(line);
		if (tokens[i].type != PARAMETER)
			asm_error(1, "Expected a parameter, stupid\n"); //print line and column as well
	}
	return (tokens);
}

uint8_t	create_ecb(t_token *tokens, uint8_t len_tokens)
{
	uint8_t ecb;
	int8_t i;

	i = -1;
	ecb = 0;
	while (++i < 3)
	{
		ecb += (i < len_tokens) ? tokens[i].subtype : 0;
		ecb <<= 2;
	}
	return (ecb);
}

