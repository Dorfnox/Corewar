/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sandwichffjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:43:56 by bpierce           #+#    #+#             */
/*   Updated: 2018/03/11 16:06:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sandwichffjoin(char **path1, char **path2, char *sandwich)
{
	char	*path;

	if (!path1 || !*path1 || !path2 || !*path2)
		return (NULL);
	if (!sandwich)
		return (ft_strffjoin(path1, path2));
	if (!(path = ft_strfjoin(path1, sandwich)))
		return (NULL);
	if (!(path = ft_strffjoin(&path, path2)))
		return (NULL);
	return (path);
}
