/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:59:04 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 00:10:57 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		epilepsy_mode(t_corewar *core, char ***av)
{
	(void)av;
	if (core->flag.epilepsy == 1)
		corewar_error("Flag '-epilepsy' should not be given twice", 1);
	return ((core->flag.epilepsy = 1));
}
