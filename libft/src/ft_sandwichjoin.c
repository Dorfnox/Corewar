/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:43:56 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/22 19:52:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sandwichjoin(char *path1, char *path2, char *sandwich)
{
	char	*path;

	if (!path1 || !path2)
		return (NULL);
	if (!sandwich)
		return (ft_strjoin(path1, path2));
	if (!(path = ft_strjoin(path1, sandwich)))
		return (NULL);
	if (!(path = ft_strfjoin(&path, path2)))
		return (NULL);
	return (path);
}
