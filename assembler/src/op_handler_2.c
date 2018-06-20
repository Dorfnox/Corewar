/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:20:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 01:19:10 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	zjump_fork_lfork_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
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
	bytes = OP_SIZE + DIR_SIZE_1;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	ldi_lldi_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 3;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[1].subtype == REG_CODE)
		INVALID_PARAM(1);
	if (tokens[2].subtype != REG_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[0].subtype == REG_CODE) ? REG_SIZE : (tokens[0].subtype == DIR_CODE) ? DIR_SIZE_1 : IND_SIZE;
	bytes += (tokens[1].subtype == DIR_CODE) ? DIR_SIZE_1 : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	sti_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 3;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	if (tokens[2].subtype == IND_CODE)
		INVALID_PARAM(2);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	bytes += (tokens[1].subtype == REG_CODE) ? REG_SIZE : (tokens[1].subtype == DIR_CODE) ? DIR_SIZE_0 : IND_SIZE;
	bytes += (tokens[2].subtype == DIR_CODE) ? DIR_SIZE_1 : REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	aff_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	t_token		*tokens;
	uint8_t		ecb;
	uint8_t		bytes;
	uint8_t		len_tokens;
	
	len_tokens = 1;
	tokens = get_params(assembler, line, len_tokens);
	if (tokens[0].subtype != REG_CODE)
		INVALID_PARAM(0);
	ecb = create_ecb(tokens, len_tokens);
	bytes = OP_SIZE + ECB_SIZE + REG_SIZE;
	enqueue_op(ops, create_ast(op_code, ecb, bytes, tokens, len_tokens));
}

void	unknown_(t_asm *assembler, t_input *line, t_ops *ops, uint8_t op_code)
{
	(void)line;
	(void)ops;
	(void)op_code;
	(void)assembler;
	asm_error(1, "????????");
}
