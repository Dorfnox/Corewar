/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:34:45 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 15:42:08 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = *alst;
	while ((*alst)->next)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = temp;
	}
	ft_lstdelone(alst, del);
}
