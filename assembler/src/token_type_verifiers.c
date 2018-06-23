/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_verifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:16:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/23 13:57:31 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

uint8_t	check_if_header(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len == 5 || len == 8)
	{
		if (!ft_strcmp(s, NAME_CMD_STRING))
			return (HEADER_NAME);
		else if (!ft_strcmp(s, COMMENT_CMD_STRING))
			return (HEADER_COMMENT);
	}
	return (0);
}

int8_t	token_is_label(char *s)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = -1;
	if (len > 1 && s[len - 1] == LABEL_CHAR)
	{
		while (++i < len - 1)
		{
			if (!(s[i] >= 'a' && s[i] <= 'z') &&
				!(s[i] >= '0' && s[i] <= '9') &&
				s[i] != '_')
				return (0);
		}
		return (1);
	}
	return (0);
}

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
	else
		return (compare_to_ops_2(s));
}

uint8_t	compare_to_ops_2(char *s)
{
	if (!ft_strcmp(s, "zjmp"))
		return (ZJMP);
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
