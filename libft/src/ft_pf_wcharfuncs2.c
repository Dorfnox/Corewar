/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_wcharfuncs2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:40:53 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/26 14:47:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	wchar_t	*tmp;
	int		i;

	if (!(tmp = ft_wstrnew(ft_wstrlen(ws))))
		return (NULL);
	i = 0;
	while (ws[i])
	{
		tmp[i] = ws[i];
		i++;
	}
	tmp[i] = L'\0';
	return (tmp);
}

void	ft_putwstr(wchar_t *ws)
{
	int i;

	i = 0;
	while (ws[i])
		ft_putwchar(ws[i++]);
}
