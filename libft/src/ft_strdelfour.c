/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelfour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:45:21 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/09 21:35:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdelfour(char **as, char **as2, char **as3, char **as4)
{
	ft_strdel(as);
	ft_strdel(as2);
	ft_strdel(as3);
	ft_strdel(as4);
}
