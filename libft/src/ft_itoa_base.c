/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:02:48 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/10 18:41:04 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** First number is in base 10.
** Second number is the base you want to convert it into.
*/

static void	convert_to_base(int n, int b, char *ans, int *p)
{
	char	*base_array;

	if (!(base_array = ft_strdup("0123456789ABCDEF")))
		return ;
	if (n <= -b || n >= b)
		convert_to_base(n / b, b, ans, p);
	ans[(*p)++] = base_array[ft_abs(n % b)];
	free(base_array);
}

char		*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || base > 16 || !(ans = ft_strnew(35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	convert_to_base(value, base, ans, &p);
	ans[p] = '\0';
	return (!(ans = ft_strfremalloc(&ans)) ? NULL : ans);
}
