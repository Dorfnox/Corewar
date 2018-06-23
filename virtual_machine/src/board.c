/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:44:36 by bpierce           #+#    #+#             */
/*   Updated: 2018/06/20 02:40:14 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_board(t_board_node **brd, t_board_node **add, t_board_node **rev)
{
	int				i;
	t_board_node	*tmp;
	t_board_node	*tmpprev;

	i = -1;
	tmp = NULL;
	tmpprev = NULL;
	while (++i < MEM_SIZE)
	{
		MALL_ERR((tmp = ft_memalloc(sizeof(t_board_node))), "Creating board");
		add[i] = tmp;
		rev[MEM_SIZE - i - 1] = tmp;
		tmpprev ? (tmpprev->next = tmp) : 0;
		tmp->prev = tmpprev;
		*brd = !(*brd) ? tmp : *brd;
		tmp->index = i;
		tmp->y = i / 64;
		tmp->x = (i % 64) * 3;
		tmp->bored_color = DF;
		tmpprev = tmp;
		tmp = tmp->next;
	}
	(*brd)->prev = tmp;
	tmpprev->next = *brd;
}

void	init_board(t_corewar *core)
{
	uint8_t		p;
	uint8_t		k;
	uint16_t	i;
	uint16_t	j;
	char		*instruction;

	create_board(&core->board, core->node_addresses, core->node_addresses_rev);
	p = -1;
	k = 0;
	while (++p < 4)
		if (core->player[p].player_num)
		{
			j = ((++k - 1) * (MEM_SIZE / core->env.num_players));
			push(&core->process_stack[0], new_process(core,
					&core->player[p], core->node_addresses[j], NULL));
			i = 0;
			while (i < core->player[p].instruction_size)
			{
				instruction = &core->player[p].header.instructions[i++];
				ft_memcpy(&core->node_addresses[j]->value, instruction, 1);
				VIZ(draw_to_bored(core, core->player[p].player_num, j, 1));
				++j;
			}
		}
}

void	dump_board(t_corewar *core)
{
	uint16_t		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 32 == 0)
			ft_printf("0x%.4x: ", i);
		ft_putstr(core->env.c_array[core->node_addresses[i]->value]);
		if ((i + 1) % 32 == 0)
			ft_putstr("\n");
		else
			ft_putstr(" ");
	}
}
