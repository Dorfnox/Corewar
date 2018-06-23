/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/23 13:54:45 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_asm	*init_asm(void)
{
	t_asm *new_asm;

	if (!(new_asm = (t_asm *)ft_memalloc(sizeof(t_asm))))
		MALLOC_ERROR();
	if (!(new_asm->header = (t_header *)ft_memalloc(sizeof(t_header))))
		MALLOC_ERROR();
	ft_memset(new_asm->header, 0, sizeof(new_asm->header));
	new_asm->header->magic = COREWAR_EXEC_MAGIC;
	new_asm->ops = init_op_queue();
	init_op_handler(new_asm);
	return (new_asm);
}

void	init_op_handler(t_asm *assembler)
{
	assembler->op_handler[0] = &unknown_;
	assembler->op_handler[1] = &live_;
	assembler->op_handler[2] = &ld_lld_;
	assembler->op_handler[3] = &st_;
	assembler->op_handler[4] = &add_sub_;
	assembler->op_handler[5] = &add_sub_;
	assembler->op_handler[6] = &and_or_xor_;
	assembler->op_handler[7] = &and_or_xor_;
	assembler->op_handler[8] = &and_or_xor_;
	assembler->op_handler[9] = &zjump_fork_lfork_;
	assembler->op_handler[10] = &ldi_lldi_;
	assembler->op_handler[11] = &sti_;
	assembler->op_handler[12] = &zjump_fork_lfork_;
	assembler->op_handler[13] = &ld_lld_;
	assembler->op_handler[14] = &ldi_lldi_;
	assembler->op_handler[15] = &zjump_fork_lfork_;
	assembler->op_handler[16] = &aff_;
}

char	*create_output_file_name(char *s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s);
	new_s = ft_strjoin(s, "or");
	new_s[--len] = 'c';
	new_s[--len] = '.';
	return (new_s);
}

void	verify_input(int ac, char **av, t_asm *assembler)
{
	size_t	len;

	if (ac != 2)
		asm_error(1, USAGE);
	len = ft_strlen(av[1]);
	if (len < 3 || av[1][len - 2] != '.' || av[1][len - 1] != 's')
		asm_error(1, USAGE);
	if ((assembler->fd = open(av[1], O_RDONLY | O_CREAT)) == -1)
		asm_error(1, "Couldn't open file");
	assembler->input_file_name = av[1];
	assembler->output_file_name = create_output_file_name(av[1]);
}

void	check_extra_tokens(t_asm *assembler, t_input *line)
{
	t_token		*token;

	token = get_next_token(line);
	if (token->type != EMPTY)
		syntax_error_with_token(assembler, line, EXTRA_TOKEN, token->value);
	free(token->value);
	free(token);
}
