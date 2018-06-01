/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:33:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/01 07:57:34 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// Doing a AST instead of this shit

// char	*get_name(char *s, char **name)
// {
// 	char	*p;
// 	char	*;

// 	if ((p = ft_strstr(s, NAME_CMD_STRING)) != NULL)
// 	{
// 		while (*p)
// 		{
// 			if (*p == CMD_DELIMITER_CHAR)
// 			{

// 			}
// 			p++;
// 		}
// 	}
// 	return (0);
// }

int parse_header(t_asm *assembler, char *file_name)
{
	int		name_set;
	int		comment_set;
	char	*line;

	
	name_set = 0;
	comment_set = 0;
	if ((assembler->fd == open(file_name, O_RDONLY)) == -1)
		asm_error(1, "Couldn't open file");
	while (ft_gnl(assembler->fd, &line) && !(name_set && comment_set))
	{
		if (!name_set && get_name(line, assembler->header->prog_name) == 1)
			name_set = 1;
		else if (!comment_set && get_name(line, assembler->header->prog_name) == 1)
			comment_set = 1;
		ft_strdel(&line);
	}
	if (!name_set || !comment_set)
		asm_error(1, "Couldn't find program's name and/or comment");
}