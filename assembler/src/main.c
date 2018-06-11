/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/10 06:22:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		main(int ac, char **av)
{
	t_asm	*assembler;

	assembler = init_asm();
	verify_input(ac, av);
	parse_input(assembler, av[1]);
	printf("total bytes: %i\n", assembler->ops->total_bytes);
	create_bytecode(assembler);
	return (0);
}
