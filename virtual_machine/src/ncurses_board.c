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
    init_ncurses_colors();   
    init_ncurses_bored(core);
    init_ncurses_playa(core);
    init_ncurses_infoz(core);
    curs_set(0);
}

void    init_ncurses_colors(void)
{
    init_pair(P1, COLOR_GREEN, COLOR_BLACK);
    init_pair(P2, COLOR_BLUE, COLOR_BLACK);
    init_pair(P3, COLOR_RED, COLOR_BLACK);
    init_pair(P4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(DF, COLOR_WHITE, COLOR_BLACK);
    init_pair(INFOZ, COLOR_BLACK, COLOR_GREEN);
}

void    init_ncurses_bored(t_corewar *core)
{
    uint16_t    i;

    core->ncur.bored = newwin(64, (64 * 2) + 63, 1, 2);
    MALL_ERR(core->ncur.bored, "Failed to create ncurses board");
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

void    init_ncurses_playa(t_corewar *core)
{
    uint8_t     i;

    i = -1;
    while (++i < MAX_PLAYERS)
    {
        if (core->player[i].player_num)
        {
            core->ncur.playa[i] = newwin(7, 40, (7 * i) + 7, 200);
            MALL_ERR(core->ncur.bored, "Failed to create ncurses playa");
            box(core->ncur.playa[i], 0, 0);
            wrefresh(core->ncur.playa[i]);
        }
    }
}

void    init_ncurses_infoz(t_corewar *core)
{
    uint16_t    width;
    uint16_t    height;
    uint16_t    i;
    uint16_t    j;

    width = 40;
    height = 6;
    core->ncur.infoz = newwin(height, width, 1, 200);
    MALL_ERR(core->ncur.infoz, "Failed to create ncurses infoz");
    wattron(core->ncur.infoz, COLOR_PAIR(INFOZ));
    wmove(core->ncur.infoz, 0, 0);
    i = 0;
    while (i++ < height)
    {
        j = 0;
        while (j++ < width)
            waddch(core->ncur.infoz, ' ');
    }
    box(core->ncur.infoz, 0, 0);
    mvwprintw(core->ncur.infoz, 1, 1, "Information");
    wrefresh(core->ncur.infoz);
}

void    draw_process(t_ncurses *n, t_process *process)
{
    uint8_t    y;
    uint8_t    x;

    
    y = process->curr_pc->index / 64;
    x = (process->curr_pc->index % 64) * 3;
    wattron(n->bored, COLOR_PAIR(process->player->player_num));
//    wattroff(n->bored, A_BOLD);
    wmove(n->bored, y, x);
//    mvwprintw(n->bored, y, x, n->c_array[process->curr_pc->value]);
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

    i = -1;
    wattron(n->bored, COLOR_PAIR(player_num));
    while (++i < n->ncur_data.value_size)
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
    }
    wrefresh(n->bored);
}

void    terminate_ncurses(t_corewar *core)
{
    if (core->flag.viz)
        endwin();
}