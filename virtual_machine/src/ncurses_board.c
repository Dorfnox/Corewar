#include "corewar.h"

/*
**  Initializes the ncurses screen, the board window
*/

void    init_ncurses(t_corewar *core)
{
    if (!core->flag.viz)
        return ;
    initscr();
    start_color();
    init_c_array(core);
    init_bored_colors();   
    init_ncurses_bored(core);
}

void    init_bored_colors(void)
{
    init_pair(P1, COLOR_GREEN, COLOR_WHITE);
    init_pair(P2, COLOR_BLUE, COLOR_WHITE);
    init_pair(P3, COLOR_RED, COLOR_WHITE);
    init_pair(P4, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(DF, COLOR_BLACK, COLOR_WHITE);
}

void    init_ncurses_bored(t_corewar *core)
{
    uint16_t    i;

    core->ncur.bored = newwin(64, (64 * 2) + 63, 10, 10);
    wattron(core->ncur.bored, COLOR_PAIR(DF));
    i = -1;
    while (++i < MEM_SIZE)
	{
        waddstr(core->ncur.bored, "00");
        if (((i + 1) % 64) != 0)
            waddch(core->ncur.bored, ' ');
	}
    wmove(core->ncur.bored, 0, 0);
    wrefresh(core->ncur.bored);
}

void    draw_process(t_ncurses *n, t_process *process)
{
    uint8_t    y;
    uint8_t    x;

    y = process->curr_pc->index / 64;
    x = (process->curr_pc->index % 64) * 3;
    wattron(n->bored, COLOR_PAIR(process->player->player_num));
    // wattron(n->bored, A_BLINK);
    wmove(n->bored, y, x);
    // mvwprintw(n->bored, y, x, n->c_array[process->curr_pc->value]);
    wrefresh(n->bored);
    //wattroff(n->bored, A_BLINK);
}

void    capture_ncur_data(t_ncurses *n, uint16_t index, uint8_t *value, uint8_t value_size)
{
    n->ncur_data.value = value;
    n->ncur_data.value_size = value_size;
    n->ncur_data.start_y = index / 64;
    n->ncur_data.start_x = (index % 64) * 3;
}

void    draw_to_bored(t_ncurses *n, uint8_t player_num)
{
    uint8_t     i;

    i = 0;
    wattron(n->bored, COLOR_PAIR(player_num));
    while (i < n->ncur_data.value_size)
    {
        mvwprintw(n->bored, n->ncur_data.start_y, n->ncur_data.start_x, 
            n->c_array[n->ncur_data.value[i]]);
        if (n->ncur_data.start_x == NCURSES_XLIMIT)
        {
            if (n->ncur_data.start_y + 1 == NCURSES_YLIMIT)
                n->ncur_data.start_y = 0;
            else
                n->ncur_data.start_y++;
            n->ncur_data.start_x = 0;
        }
        else
            n->ncur_data.start_x += 3;
        i++;
    }
    wrefresh(n->bored);
}

void    terminate_ncurses(t_corewar *core)
{
    if (core->flag.viz)
        endwin();
}