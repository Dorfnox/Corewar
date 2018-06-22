/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/21 19:49:55 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	syntax_error_with_token(t_asm *assm, t_input *line,
									char *err_msg, char *token)
{
	printf(BIWHITE "%s:%zu:%zu: " BIRED "error: " BIWHITE "%s\n" COLOR_OFF,
		assm->input_file_name, line->line_n, line->index + 1, err_msg);
	printf("\tTokenized value:\t%s\n", token);
	printf(RED "\t\t\t\t^\n" COLOR_OFF);
	exit(EXIT_FAILURE);
}

void	syntax_error_without_token(t_asm *assm, t_input *line, char *err_msg)
{
	printf("%s:%zu:%zu: " RED "error: " COLOR_OFF "%s\n",
		assm->input_file_name, line->line_n, line->index + 1, err_msg);
	exit(EXIT_FAILURE);
}

int		is_space(char c)
{
	return ((c == ' ' || c == '\t') ? (1) : (0));
}

void	asm_error(int error_code, char *error_message)
{
	if (error_message)
		printf(BIRED "error: " BIWHITE "%s\n" COLOR_OFF, error_message);
	exit(error_code);
}

int		char_at(char *s, char c, int start)
{
	if (s)
	{
		while (s[start])
		{
			if (s[start] == c)
				return (start);
			start++;
		}
	}
	return (-1);
}
