#include "corewar.h"

void    write_to_n_window(t_corewar *core, int node)
{
    waddstr(core->ncur.win, core->c_array[core->node_addresses[node]->value]);
    waddch(core->ncur.win, ' ');
}

void    init_ncursesboard(t_corewar *core)
{
    int col;
    int row;
    int i;

    col = 0;
    row = 0;
    if (!core->flag.viz)
        return ;
    initscr();
    noecho();
    core->ncur.win = newwin(70, 70, 0, 0);
    printf("heyyyyy");
    i = -1;
    while (++i < MEM_SIZE)
	{
        write_to_n_window(core, i);
		i++;
	}
}

void    terminate_ncurses(t_corewar *core)
{
    if (core->flag.viz)
        endwin();
}