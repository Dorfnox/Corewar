/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/06/10 05:26:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

size_t		hash(char *label)
{
	size_t	hash = 5381;
	int		c;
	while ((c = *label++))
		hash = ((hash << 5) + hash) +  c;
	return (hash % CAPACITY);
}

t_labels	*labelsInit(size_t capacity)
{
	t_labels	*table;

	if (!(table = (t_labels *)ft_memalloc(sizeof(t_labels))))
		asm_error(1, "Malloc error");
	if (!(table->items = (t_label_item **)ft_memalloc(capacity * sizeof(t_label_item *))))
		asm_error(1, "Malloc error");
	table->capacity = capacity;
	return (table);
}

int8_t		labelsInsert(t_labels *dict, char *key, uint32_t byte_start)
{
	size_t			tmp_hash;
	t_label_item	*new_item;

	tmp_hash = hash(key);
	if (!(new_item = (t_label_item *)ft_memalloc(sizeof(t_label_item))))
		return (0);
	new_item->key = key;
	new_item->byte_start = byte_start;
	new_item->next = dict->items[tmp_hash];
	dict->items[tmp_hash] = new_item;
	ft_strdel(&key);
	return (1);
}

uint32_t 	labelsSearch(t_labels *dict, char *key)
{
	t_label_item	*tmp_item;

	tmp_item = dict->items[hash(key)];
	while (tmp_item && ft_strcmp(tmp_item->key, key) != 0)
		tmp_item = tmp_item->next;
	if (!tmp_item || ft_strcmp(key, tmp_item->key) != 0)
		asm_error(1, "Invalid label dir param was dereferenced");
	return (tmp_item->byte_start);
}

// uint32_t searchPrice(t_labels *dict, char *name)
// {
// 	uint32_t return_value;

// 	return_value = dictSearch(dict, name);

// 	return () ? -1 : (dictSearch(dict, name)->price));
// }