#include "corewar.h"

void    live(t_corewar *core, t_process *process)
{
    uint32_t arg;

    arg = 0;
    arg |= core->board[process->reg[0]];
    ft_memcpy(&arg, core->board[process->reg[0] + 1], 4);
    if (arg < 0xFFFFFFFD)
    {
        process->reg[0] = &arg;
        return ;
}