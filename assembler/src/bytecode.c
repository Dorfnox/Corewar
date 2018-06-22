/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 05:18:07 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/21 20:32:27 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	write_bytes(int fd, uintmax_t num, uint8_t bytes)
{
	if (bytes >= 8)
		ft_putchar_fd(((num >> 56) & 0xFF), fd);
	if (bytes >= 7)
		ft_putchar_fd(((num >> 48) & 0xFF), fd);
	if (bytes >= 6)
		ft_putchar_fd(((num >> 40) & 0xFF), fd);
	if (bytes >= 5)
		ft_putchar_fd(((num >> 32) & 0xFF), fd);
	if (bytes >= 4)
		ft_putchar_fd(((num >> 24) & 0xFF), fd);
	if (bytes >= 3)
		ft_putchar_fd(((num >> 16) & 0xFF), fd);
	if (bytes >= 2)
		ft_putchar_fd(((num >> 8) & 0xFF), fd);
	if (bytes >= 1)
		ft_putchar_fd((num & 0xFF), fd);
}

void	write_params(int fd, t_ast *operation,
					t_labels *labels, uint32_t bytes_so_far)
{
	int8_t		j;
	uint32_t	tmp;
	uint8_t		bytes;

	j = -1;
	while (++j < operation->len_params)
	{
		if (operation->params[j].subtype == REG_CODE)
		{
			tmp = ft_atoi(&operation->params[j].value[1]);
			bytes = REG_SIZE;
		}
		else if (operation->params[j].subtype == IND_CODE)
		{
			tmp = ft_atoi(operation->params[j].value);
			bytes = IND_SIZE;
		}
		else if (operation->params[j].subtype == DIR_CODE)
		{
			if (operation->params[j].value[1] == LABEL_CHAR)
			{
				tmp = labels_search(labels, &operation->params[j].value[2]);
				if (tmp <= bytes_so_far)
					tmp = (0xFFFF - (bytes_so_far - tmp - 1));
				else
					tmp -= bytes_so_far;
			}
			else
				tmp = ft_atoi(&operation->params[j].value[1]);
			if ((operation->op >= LIVE && operation->op <= XOR) ||
			operation->op == LLD || operation->op == AFF)
				bytes = DIR_SIZE_0;
			else
				bytes = DIR_SIZE_1;
		}
		free(operation->params[j].value);
		write_bytes(fd, tmp, bytes);
	}
	free(operation->params);
}

void	write_ops(int fd, t_ops *ops, t_labels *labels)
{
	t_ast		*operation;
	uint16_t	bytes_so_far;

	bytes_so_far = 0;
	while (!op_queue_is_empty(ops))
	{
		operation = dequeue_op(ops);
		write_bytes(fd, operation->op, 1);
		if (operation->ecb)
			write_bytes(fd, operation->ecb, 1);
		write_params(fd, operation, labels, bytes_so_far);
		bytes_so_far += operation->bytes;
		free(operation);
	}
}

void	write_header(int fd, t_header *header)
{
	size_t	len_name;
	size_t	len_comment;

	len_name = ft_strlen(header->prog_name);
	len_comment = ft_strlen(header->comment);
	write_bytes(fd, header->magic, 4);
	write(fd, header->prog_name, PROG_NAME_LENGTH + 4);
	write_bytes(fd, header->prog_size, 4);
	write(fd, header->comment, COMMENT_LENGTH + 4);
}

void	create_bytecode(t_asm *assembler)
{
	close(assembler->fd);
	if (!(assembler->fd = open(assembler->output_file_name,
							O_WRONLY | O_TRUNC | O_CREAT, 0666)))
		asm_error(1, "Couldn't create output file");
	write_header(assembler->fd, assembler->header);
	write_ops(assembler->fd, assembler->ops, assembler->ops->labels);
}
