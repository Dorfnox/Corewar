 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:19:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 00:21:23 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	live_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 1;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype != DIR_CODE)
		INVALID_PARAM(0);
	ecb = 0;
	bytes = OP_SIZE + DIR_SIZE_0;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	ld_lld_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	bytes = 0;
	len_tokens = 2;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype == REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype != REG_CODE)
		INVALID_PARAM(1);
	ecb = create_ecb(tokens, len_tokens);
	bytes += OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	st_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 2;
	tokens = (t_token *)ft_memalloc(sizeof(t_token) * len_tokens);
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype == DIR_CODE)
		INVALID_PARAM(1);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[1].subtype == IND_CODE) ? IND_SIZE : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	add_sub_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 3;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype != REG_CODE)
		INVALID_PARAM(1);
	if (tokens[2].subtype != REG_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + (REG_SIZE * 3);
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	and_or_xor_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 3;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[2].subtype != REG_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[0].subtype == REG_CODE) ? REG_SIZE : (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : IND_SIZE;
	bytes += (tokens[1].subtype == REG_CODE) ? REG_SIZE : (tokens[1].subtype == DIR_CODE) ? DIR_SIZE_0 : IND_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}
