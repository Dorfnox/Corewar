/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/20 19:05:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

size_t		hash(char *label)
{
	size_t	hash;
	int		c;

	hash = 5381;
	while ((c = *label++))
		hash = ((hash << 5) + hash) + c;
	return (hash % CAPACITY);
}

t_labels	*labels_init(size_t capacity)
{
	t_labels	*table;

	if (!(table = (t_labels *)ft_memalloc(sizeof(t_labels))))
		MALLOC_ERROR();
	if (!(table->items = (t_label_item **)
						ft_memalloc(capacity * sizeof(t_label_item *))))
		MALLOC_ERROR();
	table->capacity = capacity;
	return (table);
}

void		labels_insert(t_labels *dict, char *key, uint32_t byte_start)
{
	size_t			tmp_hash;
	t_label_item	*new_item;

	tmp_hash = hash(key);
	if (!(new_item = (t_label_item *)ft_memalloc(sizeof(t_label_item))))
		MALLOC_ERROR();
	new_item->key = ft_strdup(key);
	new_item->byte_start = byte_start;
	new_item->next = dict->items[tmp_hash];
	dict->items[tmp_hash] = new_item;
	DBI(dict->items[tmp_hash]->byte_start);
}

uint32_t	labels_search(t_labels *dict, char *key)
{
	t_label_item	*tmp_item;

	tmp_item = dict->items[hash(key)];
	while (tmp_item && ft_strcmp(tmp_item->key, key) != 0)
		tmp_item = tmp_item->next;
	if (!tmp_item)
		asm_error(1, "Invalid label dir param was dereferenced");
	return (tmp_item->byte_start);
}
