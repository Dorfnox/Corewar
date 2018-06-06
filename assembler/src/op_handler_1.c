/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:19:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/06 00:56:32 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	live_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_token = 1;
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype != DIR_CODE)
		asm_error(1, "Expected a direct parameter, wtf??\n");
	ecb = 0;
	bytes = OP_SIZE + DIR_SIZE_0;
	enqueue_op(ops, LIVE, ecb, bytes, tokens, len_tokens);
}

void	load_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	bytes = 0;
	len_tokens = 2
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype == REG_CODE || tokens[1].subtype != REG_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens[0].subtype, tokens[1].subtype, 0);
	bytes += OP_SIZE + ECB_SIZE + DIR_SIZE_0;
	bytes += (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : REG_SIZE;
	enqueue_op(ops, LIVE, ecb, bytes, tokens, len_tokens);
}

void	st_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	
	bytes = 0;
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * 2);
	tokens[0] = get_next_token(line);
	tokens[1] = get_next_token(line);
	if (tokens[0].type != PARAMETER || tokens[1].type != PARAMETER)
		asm_error(1, "Expected a parameter, stupid\n");
	if (tokens[0].subtype != REG_CODE || tokens[1].subtype == DIR_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens[0].subtype, tokens[1].subtype, 0);
	bytes += OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[1].subtype == IND_CODE) ? IND_SIZE : REG_SIZE;
	enqueue_op(ops, LIVE, ecb, bytes, tokens);
}

void	add_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	uint8_t		i;
	
	len_tokens = 3;
	tokens = get_params(len_tokens);
	if (tokens[0].subtype != REG_CODE || tokens[1].subtype != REG_CODE || tokens[2].subtype != REG_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + DIR_SIZE_0;
	enqueue_op(ops, LIVE, ecb, bytes, tokens, len_tokens);
}

t_token		*get_params(t_input *line, uint8_t len_token)
{
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * len_tokens);
	while (i < len_tokens)
	{
		tokens[i] = get_next_token(line);
		if (tokens[i].type != PARAMETER)
			asm_error(1, "Expected a parameter, stupid\n"); //print line and column as well
	}
	return (tokens);
}

uint8_t	create_ecb(t_token *tokens, uint8_t len)
{
	uint8_t ecb;
	uint8_t i;

	i = 0;
	ecb = 0;
	while (i < 3)
	{
		ecb += (i < len) ? tokens[i].subtype : 0;
		ecb <<= 2;
	}
	return (ecb);
}
