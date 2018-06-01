/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:45:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/01 06:46:59 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	verify_input(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		asm_error(1, USAGE);
	len = ft_strlen(av[1]);
	if (len < 3  || av[1][len - 2] != '.' || av[1][len - 1] == 's')
		asm_error(1, USAGE);
}

void	asm_error(int error_code, char *error_message)
{
	if (error_message)
		write(2, error_message, ft_strlen(error_message));
	write(1, "\n", 1);
	exit(error_code);
}

t_asm	*init_asm(void)
{
	t_asm *new_asm;

	new_asm = (t_asm *)ft_memalloc(sizeof(t_asm));
	new_asm->header = (t_header *)ft_memalloc(sizeof(t_header));

	return (new_asm);
}
