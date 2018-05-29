/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pflite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:16:44 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/22 14:45:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_pflite_print_chars(va_list *ap, char *temp)
{
	unsigned int	i;
	unsigned int	j;

	if ((i = va_arg(*ap, unsigned int)))
	{
		if (!(temp = (char *)malloc(sizeof(char) * (i + 1))))
			return ;
		j = -1;
		while (++j < i)
			temp[j] = ' ';
		temp[j] = '\0';
		write(1, temp, i);
		free(temp);
	}
}

void				ft_pflite(char *s, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	j;
	char			*temp;

	i = 0;
	va_start(ap, s);
	while ((s[i] && (j = 0) == 0))
	{
		if (s[i] == '%' && s[i + 1] == '^' && (i += 2))
			ft_pflite_print_chars(&ap, temp);
		else if (s[i] == '%' && s[i + 1] == 'u' && (i += 2))
			ft_putunsignedint(va_arg(ap, unsigned int));
		else if (s[i] == '%' && s[i + 1] == 's' && (i += 2))
			if ((temp = (char *)va_arg(ap, char *)))
				write(1, temp, ft_strlen(temp));
		while (s[i + j] && s[i + j] != '%')
			j++;
		if (!s[i + j] || (s[i + j] == '%' && (j += IF_INVALID_PERCENT_ADD_ONE)))
			write(1, &s[i], j);
		i += j;
	}
	va_end(ap);
}
