/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_subtype_verifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 00:02:13 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/21 21:44:47 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

uint8_t	verify_if_register(char *s)
{
	size_t	len;
	int		reg_num;

	len = ft_strlen(s);
	if ((len > 1) && s[0] == REGISTER_CHAR)
	{
		reg_num = ft_atoi(&s[1]);
		if (reg_num >= 1 && reg_num <= 16)
			return (1);
		else
			asm_error(1, "Register params should be between 1 and 16");
	}
	return (0);
}

uint8_t	verify_if_direct(char *s)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_strlen(s);
	if (len > 2 && s[0] == DIRECT_CHAR && s[1] == LABEL_CHAR)
		return (1);
	else if (len > 1 && s[0] == DIRECT_CHAR)
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (ft_isstrdigits(&s[i]))
			return (1);
	}
	return (0);
}

uint8_t	verify_if_indirect(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (len > 0)
	{
		if (len > 1 && (s[i] == '+' || s[i] == '-'))
			i++;
		if (ft_isstrdigits(&s[i]) || s[i] == '0')
			return (1);
	}
	return (0);
}
