/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:10:59 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/23 20:25:01 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	handle_reg_code(char *s, uint32_t *tmp, uint8_t *bytes)
{
	*tmp = ft_atoi(s);
	*bytes = REG_SIZE;
}

void	handle_ind_tmp(char *s, uint32_t *tmp,
						t_labels *labels, uint32_t bytes_so_far)
{
	if (s[0] == LABEL_CHAR)
	{
		*tmp = labels_search(labels, &s[1]);
		if (*tmp <= bytes_so_far)
			*tmp = (0xFFFF - (bytes_so_far - *tmp - 1));
		else
			*tmp -= bytes_so_far;
	}
	else
		*tmp = ft_atoi(&s[0]);
}

void	handle_dir_tmp(char *s, uint32_t *tmp,
						t_labels *labels, uint32_t bytes_so_far)
{
	if (s[1] == LABEL_CHAR)
	{
		*tmp = labels_search(labels, &s[2]);
		if (*tmp <= bytes_so_far)
			*tmp = (0xFFFFFFFF - (bytes_so_far - *tmp - 1));
		else
			*tmp -= bytes_so_far;
	}
	else
		*tmp = ft_atoi(&s[1]);
}
