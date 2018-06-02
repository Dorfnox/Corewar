#include "corewar.h"

void    exec_live(uint32_t args, t_process *process, t_env *env)
{
    uint8_t player;

    player = ~args + 1;
    process->(*player).num_live++;
    process->(*player).last_live = env->cycle;
}

uint32_t    live_args(t_process **tmp)
{
    uint32_t args;

    args = 0;
    while (++i < 4)
    {
        args = args << 8;
        args |= (*tmp)->value;
        (*tmp) = (*tmp)->next;
    }
    if (args < 0xFFFFFFFC)
    {
        process->reg[0] = process->curr_pc->next;
        return 0;
    }
    return args;
}

uint8_t     live(t_corewar *core, t_process *process)
{
    uint32_t args;
    uint64_t cycle;
    t_process *tmp;

    cycle = core->env.cycle;
    tmp = process->curr_pc->next;
    if (!(args = live_args(&tmp)))
        return 0;
    process->curr_pc = tmp;
    push(core->process_stack[(cycle + 10) % 1000], (*exec_live)(args, process, &core->env));
    return 1;
}