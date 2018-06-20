/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:28:34 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	delete_asm(t_asm *assembler)
{
	free(assembler->header);
	// free(assembler->ops);
	// free(assembler);
}

int		main(int ac, char **av)
{
	t_asm	*assembler;

	assembler = init_asm();
	verify_input(ac, av, assembler);
	parse_input(assembler);
	printf("total bytes: %i\n", assembler->ops->total_bytes);
	create_bytecode(assembler);
	delete_asm(assembler);
	// while(1) ;
	return (0);
}
