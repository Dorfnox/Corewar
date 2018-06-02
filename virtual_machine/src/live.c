#include "corewar.h"

void    exec_live(uint32_t args, t_process *process, t_env *env)
{
    uint8_t player;

    player = ~args + 1;
    process->player->num_live++;
    process->player->last_live = env->cycle;
}

uint32_t    live_args(t_process *process)
{
    uint32_t    args;
    int         i;

    args = 0;
    i = -1;
    while (++i < 4)
    {
        args <<= 8;
        args |= process->curr_pc->value;  
        process->curr_pc = process->curr_pc->next;
    }
    if (args < 0xFFFFFFFC)
    {
        process->curr_pc = process->curr_pc->next;
        return 0;
    }
    return args;
}

void     live(t_corewar *core, t_process *process)
{
    uint32_t args;
    uint64_t cycle;

    cycle = core->env.cycle;
    args = live_args(process);
    if (!args)
        return ;
    exec_live(args, process, &core->env);
}