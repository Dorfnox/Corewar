/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:58:37 by bpierce           #+#    #+#             */
/*   Updated: 2018/02/25 16:15:22 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_csave(void)
{
	write(1, "\033[s", 3);
}

void	ft_crestore(void)
{
	write(1, "\033[u", 3);
}

void	ft_cforward(int num)
{
	char	*tmp;
	char	*tmp2;
	char	buf[3];

	if (num < 1)
		return ;
	tmp = ft_itoa(num);
	buf[0] = '\033';
	buf[1] = '[';
	buf[2] = '\0';
	tmp2 = ft_strjoin(buf, tmp);
	tmp2 = ft_strfjoin(&tmp2, "C");
	write(1, tmp2, ft_strlen(tmp2));
	free(tmp);
	free(tmp2);
}

void	ft_cbackward(int num)
{
	char	*tmp;
	char	*tmp2;
	char	buf[3];

	if (num < 1)
		return ;
	tmp = ft_itoa(num);
	buf[0] = '\033';
	buf[1] = '[';
	buf[2] = '\0';
	tmp2 = ft_strjoin(buf, tmp);
	tmp2 = ft_strfjoin(&tmp2, "D");
	write(1, tmp2, ft_strlen(tmp2));
	free(tmp);
	free(tmp2);
}

void	ft_cmove(int num)
{
	if (num)
	{
		if (num > 0)
			ft_cforward(num);
		else
			ft_cbackward(num);
	}
}
