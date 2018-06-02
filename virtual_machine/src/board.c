#include "corewar.h"

void    create_board(t_board_node **board, t_board_node **addresses)
{
    int i;
    (void)addresses;
    t_board_node    *tmp;
    t_board_node    *tmpprev;

    i = -1;
    tmp = NULL;
    tmpprev = NULL;
    while (++i < MEM_SIZE)
    {
        tmp = ft_memalloc(sizeof(t_board_node));
        addresses[i] = tmp;
        if (tmpprev)
            tmpprev->next = tmp;
        tmp->prev = tmpprev;
        if (!(*board))
            *board = tmp;
        tmp->index = i;
        tmpprev = tmp;
        tmp = tmp->next;
    }
    (*board)->prev = tmp;
    tmpprev->next = *board;
}

void	init_board(t_corewar *core)
{
	uint8_t p;
    uint16_t i;
    uint16_t j;
    uint8_t k;
	char *instructions;

    create_board(&core->board, core->node_addresses);
	p = 0;
    k = 0;
	while (++p < 5)
	{
        if (core->player[p - 1].player_num)
        {
            j = (++k - 1) * (MEM_SIZE / core->env.num_players);
			push(&core->process_stack[0],
                new_process(&core->player[p - 1], core->node_addresses[j]));
            i = 0;
            while (i < CHAMP_MAX_SIZE)
            {
                instructions = &core->player[p - 1].header.instructions[i++];
                ft_memcpy(&core->node_addresses[j++]->value, instructions, 1);
            }
        }
	}
}