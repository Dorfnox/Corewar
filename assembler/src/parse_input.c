/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:33:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/11 17:52:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// Doing a AST instead of this shit

// char	*get_name(char *s, char **name)
// {
// 	char	*p;
// 	int		i;
	

// 	if ((p = ft_strstr(s, NAME_CMD_STRING)) != NULL)
// 	{
// 		while (p[i])
// 		{
// 			if ()
// 		}
// 	}
// 	return (0);
// }

// int 	parse_header(t_asm *assembler, t_input *line)
// {
// 	uint8_t	name_set;
// 	uint8_t	comment_set;
// 	t_token	current_token;

// 	name_set = 0;
// 	comment_set = 0;
// 	while (ft_gnl(assembler->fd, &line) && !(name_set && comment_set))
// 	{
// 		if (!name_set && get_name(line, assembler->header->prog_name) == 1)
// 			name_set = 1;
// 		else if (!comment_set && get_name(line, assembler->header->prog_name) == 1)
// 			comment_set = 1;
// 		ft_strdel(&line);
// 	}
// 	if (!name_set || !comment_set)
// 		asm_error(1, "Couldn't find program's name and/or comment");
// }

void	parse_operations(t_asm *assembler, t_input *line)
{
	t_token		current_token;
	char		*label_carry;

	label_carry = NULL;
	while (ft_gnl(assembler->fd, &line->s) > 0)
	{
		ft_bzero(&current_token, sizeof(current_token));
		line->len = ft_strlen(line->s);
		current_token = get_next_token(line);
		if (current_token.type == LABEL)
		{
			if (label_carry != NULL)
				asm_error(1, "Expected an op, stupid\n");
			label_carry = current_token.value;
			current_token = get_next_token(line);
		}
		if (current_token.type == OPERATION)
		{
			if (label_carry != NULL)
				labelsInsert(assembler->ops->labels, label_carry, assembler->ops->total_bytes + 1);
			assembler->op_handler[current_token.subtype](line, assembler->ops, current_token.subtype);
		}
		else if (current_token.type != EOL || current_token.type != COMMENT)
			asm_error(1, ft_str256(2, "Invalid syntax in line ", itoa(line->line_n)));
		line->line_n++;
		ft_bzero((void *)line, sizeof(t_input));
	}
}

void		parse_input(t_asm *assembler, char *file)
{
	t_input		*line;

	line = (t_input *)ft_memalloc(sizeof(t_input));
	if ((assembler->fd = open(file, O_RDONLY)) == -1)
		asm_error(1, "Couldn't open file");
	parse_operations(assembler, line);
}
