/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 05:18:07 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/11 09:20:38 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// uint8_t	*resolve_params(t_token *params, uint8_t len_params, t_labels *labels)
// {
// 	uint8_t	*arr;
// 	int8_t	i;

// 	arr = (uint8_t *)ft_memalloc(sizeof(uint8_t) * len_params);
// 	while (++i < len_params)
// 	{
// 		if (params[i].subtype == REG_CODE)
			
// 	}
// }

// int32_t	get_int()
// {
	
// }

void	add_int_to_bytes(int32_t num, uint8_t num_bytes, int fd)
{

	if (num_bytes == REG_SIZE)
		ft_putchar_fd((num & 0xF), fd);
		// (*byte_arr)[(*i)++] = num & 0xFF;
	else if (num_bytes == IND_SIZE || num_bytes == DIR_SIZE_1)
	{
		ft_putchar_fd(((num >> 8) & 0xFF), fd);
		ft_putchar_fd((num & 0xF), fd);
		// (*byte_arr)[(*i)++] = (num >> 8) & 0xFF;
		// (*byte_arr)[(*i)++] = num & 0xFF;		
	}
	else if (num_bytes == DIR_SIZE_0)
	{
		ft_putchar_fd(((num >> 24) & 0xFF), fd);
		ft_putchar_fd(((num >> 16) & 0xFF), fd);
		ft_putchar_fd(((num >> 8) & 0xFF), fd);
		ft_putchar_fd((num & 0xF), fd);
		// (*byte_arr)[(*i)++] = (num >> 24) & 0xFF;
		// (*byte_arr)[(*i)++] = (num >> 16) & 0xFF;
		// (*byte_arr)[(*i)++] = (num >> 8) & 0xFF;
		// (*byte_arr)[(*i)++] = num & 0xFF;
	}
}

void	write_next_ast_into_file(t_asm *assembler)
{
	t_ast		*operation;
	int32_t		tmp;
	int8_t		j;
	
	j = -1;
	operation = dequeue_op(assembler->ops);
	// (*byte_arr)[++(*i)] = operation->op;
	ft_putchar_fd(operation->op, assembler->fd);
	if (operation->ecb)
		ft_putchar_fd(operation->ecb, assembler->fd);
		// (*byte_arr)[(*i)++] = operation->ecb;
	printf("Op_code: %d, ecb: %d, params %d\n", operation->op, operation->ecb, operation->len_params);
	while (++j < operation->len_params)
	{
		if (operation->params[j].subtype == REG_CODE)
		{
			tmp = ft_atoi(&operation->params[j].value[1]);
			add_int_to_bytes(tmp, REG_SIZE, assembler->fd);
		}
		else if (operation->params[j].subtype == IND_CODE)
		{
			tmp = ft_atoi(operation->params[j].value);
			add_int_to_bytes(tmp, IND_SIZE, assembler->fd);
		}
		else if (operation->params[j].subtype == DIR_CODE)
		{
			if (operation->params[j].value[1] == LABEL_CHAR)
				tmp = labelsSearch(assembler->ops->labels, &operation->params[j].value[2]);
			else
				tmp = ft_atoi(&operation->params[j].value[1]);
			if ((operation->op >= LIVE && operation->op <= XOR) ||
			operation->op == LLD || operation->op == AFF)
				add_int_to_bytes(tmp, DIR_SIZE_0, assembler->fd);
			else
				add_int_to_bytes(tmp, DIR_SIZE_1, assembler->fd);
		}
	}
}

void	create_bytecode(t_asm *assembler)
{
	uint8_t		*byte_arr;
	uint16_t	i;

	i = 0;
	close(assembler->fd);
	if (!(assembler->fd = open("test.cor", O_WRONLY | O_CREAT, 0666)))
		asm_error(1, "Couldn't create output file");
	byte_arr = (uint8_t *)ft_memalloc(sizeof(uint8_t) * assembler->ops->total_bytes);
	while (!op_queue_is_empty(assembler->ops))
		write_next_ast_into_file(assembler);
	// write(assembler->fd, byte_arr, assembler->ops->total_bytes);
}