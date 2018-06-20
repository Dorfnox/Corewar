/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:33:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/19 17:05:52 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	get_header_value(t_asm *assembler, t_input *line, uint8_t subtype)
{
	int16_t	value_start;
	int16_t	value_end;
	size_t	char_at_start;
	size_t	max_chars;
	char	*value;
	
	char_at_start = (subtype == HEADER_NAME) ? ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	max_chars = (subtype == HEADER_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	if ((value_start = char_at(line->s, COMMENT_DELIMITER_CHAR, char_at_start)) == -1)
		syntax_error_without_token(assembler, line, HEADER_VALUE_ABSENT);
	if ((value_end = char_at(line->s, COMMENT_DELIMITER_CHAR, value_start + 1)) == -1)
		syntax_error_without_token(assembler, line, HEADER_VALUE_INCOMPLETE);
	value = ft_strsub(line->s, value_start + 1, (value_end - value_start - 1));
	if (ft_strlen(value) > max_chars)
		syntax_error_without_token(assembler, line, HEADER_VALUE_LONG);
	if (subtype == HEADER_NAME)
		ft_strcpy(assembler->header->prog_name, value);
	else
		ft_strcpy(assembler->header->comment, value);
	ft_strdel(&value);
}

void	parse_header(t_asm *assembler, t_input *line, t_token *current_token, int *name_set, int *comment_set)
{
	if (current_token->type == HEADER && current_token->subtype == HEADER_NAME)
	{
		if (*name_set)
			syntax_error_without_token(assembler, line, HEADER_NAME_REPEATED);
		get_header_value(assembler, line, current_token->subtype);
		*name_set = 1;
	}
	else if (current_token->type == HEADER && current_token->subtype == HEADER_COMMENT)
	{
		if (!*name_set)
			syntax_error_without_token(assembler, line, HEADER_COMMENT_FIRST);
		if (*comment_set)
			syntax_error_without_token(assembler, line, HEADER_COMMENT_REPEATED);
		get_header_value(assembler, line, current_token->subtype);
		*comment_set = 1;
	}
	else if (current_token->type != EMPTY)
		syntax_error_with_token(assembler, line, UNEXPECTED_TOKEN, current_token->value);
}

void	parse_operations(t_asm *assembler, t_input *line, t_token *current_token, char *label_carry)
{
	if (current_token->type == LABEL)
	{
		if (label_carry != NULL)
		syntax_error_with_token(assembler, line, HEADER_VALUE_INCOMPLETE, current_token->value);
			asm_error(1, "Expected an op, stupid\n");
		label_carry = current_token->value;
		current_token = get_next_token(line);
	}
	if (current_token->type == OPERATION)
	{
		if (label_carry != NULL)
			labelsInsert(assembler->ops->labels, label_carry, assembler->ops->total_bytes + 1);
		assembler->op_handler[current_token->subtype](line, assembler->ops, current_token->subtype);
	}
	else if (current_token->type != EMPTY)
		asm_error(1, ft_str128(2, "Invalid syntax in line ", ft_itoa(line->line_n)));
}

void	read_file(t_asm *assembler, t_input *line)
{
	t_token		*current_token;
	char		*label_carry;
	int			name_set;
	int			comment_set;

	label_carry = NULL;
	name_set = 0;
	comment_set = 0;
	while (ft_gnl(assembler->fd, &(line->s)) > 0)
	{
		remove_comment(&line->s);
		ft_bzero(&current_token, sizeof(current_token));
		line->len = ft_strlen(line->s);
		printf("len: %zu\n", line->len);
		current_token = get_next_token(line);
		if (!name_set || !comment_set)
			parse_header(assembler, line, current_token, &name_set, &comment_set);
		else
			parse_operations(assembler, line, current_token, label_carry);
		line->line_n++;
		line->index = 0;
		// ft_bzero((void *)line, sizeof(t_input));
		// if (line->s)
		// 	ft_strclr(line->s);
	}
}

void		parse_input(t_asm *assembler)
{
	t_input		*line;

	line = (t_input *)ft_memalloc(sizeof(t_input));
	line->line_n = 1;
	read_file(assembler, line);
	// parse_header(assembler, line);
	printf("Name: %s, Header: %s\n", assembler->header->prog_name, assembler->header->comment);
	// parse_operations(assembler, line);
	assembler->header->prog_size = assembler->ops->total_bytes;
	free(line);
}
