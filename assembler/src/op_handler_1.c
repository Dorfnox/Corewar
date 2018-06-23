/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:19:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/23 13:43:11 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	live_(t_asm *assembler, t_input *line,
			t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_toks;

	len_toks = len_tokens(op_code);
	tokens = get_params(assembler, line, len_toks);
	if (tokens[0].subtype != DIR_CODE)
		INVALID_PARAM(0);
	ecb = 0;
	bytes = OP_SIZE + DIR_SIZE_0;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens));
}

void	ld_lld_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_toks;

	len_toks = len_tokens(op_code);
	bytes = 0;
	tokens = get_params(assembler, line, len_toks);
	if (tokens[0].subtype == REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype != REG_CODE)
		INVALID_PARAM(1);
	ecb = create_ecb(tokens, len_toks);
	bytes += OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_0 : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens));
}

void	st_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_toks;

	len_toks = len_tokens(op_code);
	tokens = get_params(assembler, line, len_toks);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype == DIR_CODE)
		INVALID_PARAM(1);
	ecb = create_ecb(tokens, len_toks);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[1].subtype == IND_CODE) ? IND_SIZE : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens));
}

void	add_sub_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_toks;

	len_toks = len_tokens(op_code);
	tokens = get_params(assembler, line, len_toks);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	if (tokens[1].subtype != REG_CODE)
		INVALID_PARAM(1);
	if (tokens[2].subtype != REG_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_toks);
	bytes = OP_SIZE + ECB_SIZE + (REG_SIZE * 3);
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens));
}

void	and_or_xor_(t_asm *assembler, t_input *line,
					t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_toks;

	len_toks = len_tokens(op_code);
	tokens = get_params(assembler, line, len_toks);
	if (tokens[2].subtype != REG_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_toks);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	if (tokens[0].subtype == REG_CODE)
		bytes += REG_SIZE;
	else if (tokens[0].subtype == DIR_CODE)
		bytes += DIR_SIZE_0;
	else
		bytes += IND_SIZE;
	if (tokens[1].subtype == REG_CODE)
		bytes += REG_SIZE;
	else if (tokens[1].subtype == DIR_CODE)
		bytes += DIR_SIZE_0;
	else
		bytes += IND_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens));
}
