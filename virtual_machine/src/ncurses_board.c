#include "corewar.h"

/*
**  Initializes the ncurses screen, the board window
*/

void    init_ncurses(t_corewar *core)
{
    if (!core->flag.viz)
        return ;
    initscr();
    noecho();
    cbreak();
    start_color();
    init_ncurses_colors();   
    init_ncurses_arrays(core);
    init_ncurses_bored(core);
    init_ncurses_playa(core);
    init_ncurses_infoz(core);
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    sleep(1);
}

void    init_ncurses_colors(void)
{
    init_pair(P1, COLOR_GREEN, COLOR_BLACK);
    init_pair(P2, COLOR_BLUE, COLOR_BLACK);
    init_pair(P3, COLOR_RED, COLOR_BLACK);
    init_pair(P4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(P1B, COLOR_BLACK, COLOR_GREEN);
    init_pair(P2B, COLOR_BLACK, COLOR_BLUE);
    init_pair(P3B, COLOR_BLACK, COLOR_RED);
    init_pair(P4B, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(DF, COLOR_WHITE, COLOR_BLACK);
    init_pair(INFOZ, COLOR_BLACK, COLOR_GREEN);
}

void    init_ncurses_bored(t_corewar *core)
{
    uint16_t    i;

    core->ncur.bored = newwin(64, (64 * 2) + 63, 0, 0);
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
    core->ncur.infoz = newwin(height, width, 0, 200);
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
    wclear(core->ncur.infoz);
    box(core->ncur.infoz, 0, 0);
    mvwprintw(core->ncur.infoz, 1, 1, "Information");
    wrefresh(core->ncur.infoz);
}

void    draw_to_bored(t_corewar *core, uint8_t player_num,
    uint16_t idx, uint8_t len)
{
    uint8_t     i;

    i = -1;
    while (++i < len)
    {
        mvwprintw(core->ncur.infoz, 4, 0, "player num: %i", player_num);
        wrefresh(core->ncur.infoz);
        core->ncur.cursor[idx].bored_color = player_num;
        draw_cursor(core, &core->ncur.cursor[idx]);
        idx = ((idx + 1) == MEM_SIZE) ? 0 : (idx + 1);
    }
}


int     key_hit(void)
{
    int             ch;

    if ((ch = getch()) == ERR)
    {
        return (1);
    }
    else if (ch == ' ')
    {
        while ((ch = getch()) != ' ')
            ;
    }
    return (1);
}

void    terminate_ncurses(t_corewar *core)
{
    if (core->flag.viz)
        endwin();
}