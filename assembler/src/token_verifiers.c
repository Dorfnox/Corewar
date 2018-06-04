/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_verifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 00:02:13 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/02 00:07:57 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// this is prob going to change to a jump table
uint8_t	compare_to_ops(char *s)
{
	if (!ft_strcmp(s, "live"))
		return (LIVE);
	else if (!ft_strcmp(s, "ld"))
		return (LD);
	else if (!ft_strcmp(s, "st"))
		return (ST);
	else if (!ft_strcmp(s, "add"))
		return (ADD);
	else if (!ft_strcmp(s, "sub"))
		return (SUB);
	else if (!ft_strcmp(s, "and"))
		return (AND);
	else if (!ft_strcmp(s, "or"))
		return (OR);
	else if (!ft_strcmp(s, "xor"))
		return (XOR);
	else if (!ft_strcmp(s, "zjump"))
		return (ZJUMP);
	else if (!ft_strcmp(s, "ldi"))
		return (LDI);
	else if (!ft_strcmp(s, "sti"))
		return (STI);
	else if (!ft_strcmp(s, "fork"))
		return (FORK);
	else if (!ft_strcmp(s, "lld"))
		return (LLD);
	else if (!ft_strcmp(s, "lldi"))
		return (LLDI);
	else if (!ft_strcmp(s, "lfork"))
		return (LFORK);
	else if (!ft_strcmp(s, "aff"))
		return (AFF);
	else
		return (0);
}

uint8_t	verify_if_register(char *s)
{
	size_t	len;
	int		reg_num;

	len = ft_strlen(s);
	if ((len == 2 || len == 3) && s[0] == REGISTER_CHAR)
	{
		reg_num = ft_atoi(&s[1]);
		if (reg_num >= 1 && reg_num <= 16)
			return (1);
	}
	return (0);
}

uint8_t verify_if_direct(char *s)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_strlen(s);
	if (len > 2 && s[0] == DIRECT_CHAR && s[1] == LABEL_CHAR)
		return (1);
	else if (len > 1 && s[0] == DIRECT_CHAR && ft_isstrdigits(&s[1]))
		return (1);
	return (0);
}

uint8_t	verify_if_indirect(char *s)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(s);
	if (len > 0)
	{
		if (len > 1 && (s[i] == '+' || s[i] == '-'))
			i++;
		if (ft_isstrdigits(&s[i]))
			return (1);
	}
	return (0);
}

uint8_t	compare_to_params(char *s)
{
	if (verify_if_register(s))
		return (REG_CODE);
	else if (verify_if_direct(s))
		return (DIR_CODE);
	else if (verify_if_indirect(s))
		return (IND_CODE);
	else
		return (0);
}

