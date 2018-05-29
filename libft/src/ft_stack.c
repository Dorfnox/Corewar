/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 09:38:53 by exam              #+#    #+#             */
/*   Updated: 2018/05/15 17:47:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*inits(void)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->top = NULL;
	new->size = 0;
	return (new);
}

void		push(t_stack *s, void *content)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return ;
	new->content = content;
	new->next = s->top ? s->top : NULL;
	s->top = new;
	++s->size;
}

void		*pop(t_stack *s)
{
	t_node	*to_delete;
	void	*content;

	if (!s->top)
		return (NULL);
	content = s->top->content;
	to_delete = s->top;
	s->top = s->top->next;
	free(to_delete);
	--s->size;
	return (content);
}

void		*peeks(t_stack *s)
{
	return (s->top ? s->top->content : NULL);
}

int			isemptys(t_stack *s)
{
	return (s->top ? 0 : 1);
}
