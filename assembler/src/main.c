/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:57:13 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/21 20:33:07 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	delete_asm(t_asm *assembler)
{
	free(assembler->output_file_name);
	free(assembler->header);
	labels_delete(assembler->ops->labels);
	free(assembler->ops);
	free(assembler);
}

int		main(int ac, char **av)
{
	t_asm	*assembler;

	assembler = init_asm();
	verify_input(ac, av, assembler);
	parse_input(assembler);
	ft_pflite(BIGREEN "Creating champ:" BIWHITE " %s...\n" COLOR_OFF,
				assembler->output_file_name);
	create_bytecode(assembler);
	delete_asm(assembler);
	return (0);
}
