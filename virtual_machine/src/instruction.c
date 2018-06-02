#include "corewar.h"

void       init_instruction_array_and_wait_times(t_corewar *core)
{
    core->wait_time[1] = 10;
    core->instr[0] = live;
    core->instr[1] = live;
}