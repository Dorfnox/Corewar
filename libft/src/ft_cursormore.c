/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursormore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:58:37 by bpierce           #+#    #+#             */
/*   Updated: 2018/02/25 17:09:37 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cplace(int row, int column)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (row < 1 || column < 1)
		return ;
	tmp = ft_itoa(row);
	tmp2 = ft_itoa(column);
	tmp3 = ft_strjoin("\033[", tmp);
	tmp3 = ft_strfjoin(&tmp3, ";");
	tmp3 = ft_strfjoin(&tmp3, tmp2);
	tmp3 = ft_strfjoin(&tmp3, "H");
	write(1, tmp3, ft_strlen(tmp3));
	free(tmp);
	free(tmp2);
	free(tmp3);
}

/*
** ft_cclearscreen(int num)
**	- 0, clears from cursor to end of screen
**	- 1, clears from cursor to beginning of screen
**	- 2, clears entire screen
*/

void	ft_cclearscreen(int num)
{
	if (num != 0 && num != 1 && num != 2)
		return ;
	ft_pflite("\033[%uJ", num);
}

/*
** ft_cclearline(int num)
**	- 0, clears from cursor to end of line
**	- 1, clears from cursor to beginning of line
**	- 2, clears entire line
*/

void	ft_cclearline(int num)
{
	if (num != 0 && num != 1 && num != 2)
		return ;
	ft_pflite("\033[%uK", num);
}
