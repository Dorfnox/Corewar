/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:29:40 by bpierce           #+#    #+#             */
/*   Updated: 2018/05/28 12:50:52 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# define DB(x)  ft_debug((x))
# define DBI(x) ft_debug(ft_itoa((x)))

# define CE_(a, b) ((a) == (b))
# define CE_2(a, b, c) (CE_(a, b) || CE_(a, c))
# define CE_3(a, b, c, d) (CE_2(a, b, c) || CE_(a, d))
# define CE_4(a, b, c, d, e) (CE_2(a, b, c) || CE_2(a, d, e))
# define CE_5(a, b, c, d, e, f) (CE_3(a, b, c, d) || CE_2(a, e, f))

# define SE_(a, b) (ft_strequ((a), (b)))
# define SE_2(a, b, c) (SE_(a, b) || SE_(a, c))
# define SE_3(a, b, c, d) (SE_2(a, b, c) || CE_(a, d))
# define SE_4(a, b, c, d, e) (SE_2(a, b, c) || SE_2(a, d, e))
# define SE_5(a, b, c, d, e, f) (SE_3(a, b, c, d) || SE_2(a, e, f))

# define MIN(a, b) (a < b ? a : b)
# define MAX(a, b) (a > b ? a : b)

#endif
