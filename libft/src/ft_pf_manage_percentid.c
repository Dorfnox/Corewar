/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_manage_percentid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:01:27 by bpierce           #+#    #+#             */
/*   Updated: 2017/12/20 20:06:00 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Continue managing the percentid member variables.
*/

static void			continue_readjusting_percentid(t_printf **p)
{
	if (PFT == DD_TYPE || PFT == OO_TYPE || PFT == UU_TYPE)
	{
		PFT = (PFT == DD_TYPE) ? L_TYPE : PFT;
		PFT = (PFT == OO_TYPE) ? UL_TYPE : PFT;
		PFT = (PFT == UU_TYPE) ? UL_TYPE : PFT;
		(*p)->pid->len = L_L;
	}
	if ((*p)->pid->len == L_L)
	{
		PFT = (PFT == S_TYPE) ? WS_TYPE : PFT;
		PFT = (PFT == C_TYPE) ? WC_TYPE : PFT;
	}
	(*p)->pid->base = (PFT == P_TYPE) ? 16 : (*p)->pid->base;
	(*p)->pid->f_alt = (PFT == P_TYPE) ? 16 : (*p)->pid->f_alt;
}

/*
** Type promotion and exception management.
*/

static void			readjust_percentid(t_printf **p, char *s, int j)
{
	if (ft_isnumericconversionchar(s[j - 1]))
	{
		(*p)->pid->f_zero = (((*p)->pid->precision != -1 ||
					(*p)->pid->f_ladj != -1) ? -1 : (*p)->pid->f_zero);
		(*p)->pid->f_space = ((*p)->pid->f_sign != -1
				? -1 : (*p)->pid->f_space);
	}
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_HH) ? SC_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_HH) ? UC_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_H) ? SH_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_H) ? USH_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_L) ? L_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_LL) ? LL_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_L) ? UL_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_LL) ? ULL_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_J) ? IM_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_J) ? UIM_TYPE : PFT;
	PFT = (IS_DI(PFT)) && ((*p)->pid->len == L_Z) ? ST_TYPE : PFT;
	PFT = (IS_OUX(PFT)) && ((*p)->pid->len == L_Z) ? ST_TYPE : PFT;
	continue_readjusting_percentid(p);
}

/*
** Returns pointer to malloc'd s_percentid struct for storing
** data on how to print given argument.
*/

static t_percentid	*new_percentid(void)
{
	t_percentid		*new;

	if (!(new = (t_percentid *)ft_memalloc(sizeof(t_percentid))))
		return (NULL);
	new->field_width = -1;
	new->precision = -1;
	new->len = -1;
	new->f_alt = -1;
	new->f_zero = -1;
	new->f_ladj = -1;
	new->f_space = -1;
	new->f_sign = -1;
	new->base = 10;
	new->xbase = -1;
	new->fmt = NULL;
	return (new);
}

/*
** Helper function for setting pointers to functions.
** Each of these functions set s_percentid member variables.
** Functions can be found in set_percentid.c file.
** In store_percentid(), allows breaking of set_loop as soon as j == -1,
** indicating there was a problem with the given parameters somewhere.
*/

static void			initialize_setfunc(t_setfunc *set)
{
	set[0].f = &set_pf_flags;
	set[1].f = &set_pf_fieldwidth;
	set[2].f = &set_pf_precision;
	set[3].f = &set_pf_length;
	set[4].f = &set_pf_type;
}

/*
** Stores given %... argument in s_percentid struct.
*/

int					store_percentid(t_printf **p, char *s, va_list *ap, int i)
{
	int			j;
	int			k;
	t_setfunc	set[5];

	j = 0;
	k = 0;
	initialize_setfunc(set);
	(*p)->next = ((*p)->type != -1) ? new_printlst() : NULL;
	*p = ((*p)->type != -1) ? (*p)->next : *p;
	if (s[++j])
	{
		if (!((*p)->pid = new_percentid()))
			return (-1);
		while (j != -1 && k < 5)
			j = set[k++].f(p, s, j);
		if (j != -1)
		{
			readjust_percentid(p, s, j);
			if (!(store_datafmt(p, ap)))
				return (-1);
			return (j + i);
		}
	}
	return (-1);
}
