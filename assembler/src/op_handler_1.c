/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_1-5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:19:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/08 00:10:36 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	live_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 1;
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype != DIR_CODE)
		asm_error(1, "Expected a direct parameter, wtf??\n");
	ecb = 0;
	bytes = OP_SIZE + DIR_SIZE_0;
	enqueue_op(ops, create_ast(LIVE, ecb, bytes, tokens));
}

void	ld_lld_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	bytes = 0;
	len_tokens = 2;
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype == REG_CODE || tokens[1].subtype != REG_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens, len_tokens);
	bytes += OP_SIZE + ECB_SIZE + DIR_SIZE_0;
	bytes += (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : REG_SIZE;
	enqueue_op(ops, create_ast(LIVE, ecb, bytes, tokens));
}

void	st_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 2;
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * len_tokens);
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype != REG_CODE || tokens[1].subtype == DIR_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[1].subtype == IND_CODE) ? IND_SIZE : REG_SIZE;
	enqueue_op(ops, create_ast(LIVE, ecb, bytes, tokens));
}

void	add_sub_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 3;
	tokens = get_params(line, len_tokens);
	if (tokens[0].subtype != REG_CODE || tokens[1].subtype != REG_CODE || tokens[2].subtype != REG_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + (REG_SIZE * 3);
	enqueue_op(ops, create_ast(LIVE, ecb, bytes, tokens));
}

void	and_or_xor_(t_input *line, t_ops *ops)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	uint8_t		i;
	
	len_tokens = 3;
	tokens = get_params(line, len_tokens);
	if (tokens[2].subtype != REG_CODE)
		asm_error(1, "Invalid param type, wtf??\n");
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[0].subtype == REG_CODE) ? REG_SIZE : (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : IND_SIZE;
	bytes += (tokens[1].subtype == REG_CODE) ? REG_SIZE : (tokens[1].subtype == DIR_CODE) ? DIR_SIZE_0 : IND_SIZE;
	enqueue_op(ops, create_ast(LIVE, ecb, bytes, tokens));
}
