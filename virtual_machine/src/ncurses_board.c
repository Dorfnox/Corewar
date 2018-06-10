#include "corewar.h"

void    init_ncursesbored(t_corewar *core)
{
    uint16_t    i;

    if (!core->flag.viz)
        return ;
    initscr();
    init_bored_colors();
    core->ncur.bored = newwin(64, (64 * 2) + 63, 10, 10);
    wattron(core->ncur.bored, COLOR_PAIR(DF));
    i = -1;
    while (++i < MEM_SIZE)
	{
        waddstr(core->ncur.bored,
            core->ncur.c_array[core->node_addresses[i]->value]);
        if (((i + 1) % 64) != 0)
            waddch(core->ncur.bored, ' ');
	}
    // core->ncur.bored.border.ls = '|';
	// core->ncur.bored.border.rs = '|';
	// core->ncur.bored.border.ts = '-';
	// core->ncur.bored.border.bs = '-';
	// core->ncur.bored.border.tl = '+';
	// core->ncur.bored.border.tr = '+';
	// core->ncur.bored.border.bl = '+';
	// core->ncur.bored.border.br = '+';
    wrefresh(core->ncur.bored);
}

void    init_bored_colors(void)
{
    start_color();
    init_pair(P1, COLOR_GREEN, COLOR_WHITE);
    init_pair(P2, COLOR_BLUE, COLOR_WHITE);
    init_pair(P3, COLOR_RED, COLOR_WHITE);
    init_pair(P4, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(DF, COLOR_BLACK, COLOR_WHITE);
}

void    draw_process(t_ncurses *n, t_process *process)
{
    uint8_t    y;
    uint8_t    x;

    y = process->curr_pc->index / 64;
    x = (process->curr_pc->index % 64) * 3;
    wattron(n->bored, A_BLINK);
    wattron(n->bored, COLOR_PAIR(process->player->player_num));
    mvwprintw(n->bored, y, x, n->c_array[process->curr_pc->value]);
    wrefresh(n->bored);
    //wattroff(n->bored, A_BLINK);
}

void    terminate_ncurses(t_corewar *core)
{
    if (core->flag.viz)
        endwin();
}