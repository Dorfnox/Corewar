/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:33:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/21 19:45:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	get_header_value(t_asm *assembler, t_input *line, uint8_t subtype)
{
	int16_t	value_start;
	int16_t	value_end;
	size_t	start;
	size_t	max_chars;
	char	*value;

	start = (subtype == HEADER_NAME) ?
		ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	max_chars = (subtype == HEADER_NAME) ? PROG_NAME_LENGTH : COMMENT_LENGTH;
	if ((value_start = char_at(line->s, COMMENT_DELIMITER_CHAR, start)) == -1)
		syntax_error_without_token(assembler, line, HEADER_VALUE_ABSENT);
	if ((value_end =
			char_at(line->s, COMMENT_DELIMITER_CHAR, value_start + 1)) == -1)
		syntax_error_without_token(assembler, line, HEADER_VALUE_INCOMPLETE);
	value = ft_strsub(line->s, value_start + 1, (value_end - value_start - 1));
	if (ft_strlen(value) > max_chars)
		syntax_error_without_token(assembler, line, HEADER_VALUE_LONG);
	if (subtype == HEADER_NAME)
		ft_strcpy(assembler->header->prog_name, value);
	else
		ft_strcpy(assembler->header->comment, value);
	ft_strdel(&value);
	line->index = value_end + 1;
}

void	parse_header(t_asm *assembler, t_input *line,
					t_token *current_token, uint8_t *name_comment_set)
{
	if (current_token->type == HEADER && current_token->subtype == HEADER_NAME)
	{
		if ((*name_comment_set & 1) == 1)
			syntax_error_without_token(assembler, line, HEADER_NAME_REPEAT);
		get_header_value(assembler, line, current_token->subtype);
		*name_comment_set |= 1;
	}
	else if (current_token->type == HEADER &&
			current_token->subtype == HEADER_COMMENT)
	{
		if (!((*name_comment_set) & 1))
			syntax_error_without_token(assembler, line, HEADER_COMMENT_FIRST);
		if ((*name_comment_set & 2) == 2)
			syntax_error_without_token(assembler, line, HEADER_COMMENT_REPEAT);
		get_header_value(assembler, line, current_token->subtype);
		*name_comment_set |= 2;
	}
	else if (current_token->type != EMPTY)
		syntax_error_with_token(assembler, line, UNEXPECTED_TOKEN,
								current_token->value);
}

void	parse_operations(t_asm *assembler, t_input *line,
						t_token *current_token, char **label_carry)
{
	if (current_token->type == LABEL)
	{
		if (*label_carry != NULL)
			syntax_error_with_token(assembler, line, OPERATION_LABEL_DOUBLE,
									current_token->value);
		*label_carry = ft_strdup(current_token->value);
        free(current_token->value);
        free(current_token);
		current_token = get_next_token(line);
	}
	if (current_token->type == OPERATION)
	{
		if (*label_carry != NULL)
			labels_insert(assembler->ops->labels, label_carry,
						assembler->ops->total_bytes);
		assembler->op_handler[current_token->subtype](
			assembler, line, assembler->ops, current_token->subtype);

	}
	else if (current_token->type != EMPTY)
		syntax_error_with_token(assembler, line, UNEXPECTED_TOKEN,
								current_token->value);
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

void	read_file(t_asm *assembler, t_input *line)
{
	t_token		*current_token;
	char		*label_carry;
	uint8_t		name_comment_set;
	char		*s;

	label_carry = NULL;
	name_comment_set = 0;
	while (ft_gnl(assembler->fd, &s) > 0)
	{
		line->s = remove_comment(s);
		line->len = ft_strlen(line->s);
		current_token = get_next_token(line);
		if (name_comment_set != 3)
			parse_header(assembler, line, current_token, &name_comment_set);
		else
			parse_operations(assembler, line, current_token, &label_carry);
        free(current_token->value);
        free(current_token);
		check_extra_tokens(assembler, line);
		free(line->s);
		line->line_n++;
		line->index = 0;
	}
    if (label_carry)
        asm_error(EXIT_FAILURE, "Label at the end pointing to nuthin");
}

void	parse_input(t_asm *assembler)
{
	t_input		*line;

	line = (t_input *)ft_memalloc(sizeof(t_input));
	line->line_n = 1;
	read_file(assembler, line);
	if (!assembler->ops->total_bytes)
		asm_error(1, "No operations found");
	assembler->header->prog_size = assembler->ops->total_bytes;
	free(line);
}
