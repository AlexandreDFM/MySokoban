/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Function principal about sokoban
*/

#include "sokoban.h"

int check_map(char *map, sokoban_t *sokoban)
{
    int line = 0;
    int size_one_line = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n' && size_one_line == 0)
            size_one_line = i - 1;
        if (map[i] == '\n')
            line += 1;
        if (map[i] == 'P') {
            sokoban->posx = i - size_one_line * line - line * 2;
            sokoban->posy = line;
        } else if (map[i] == ' ' || map[i] == '\n' || map[i] == '#'
        || map[i] == 'X' || map[i] == 'O' || map[i] == 'P' || map[i] == '\0') {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}

int print_win_lose(sokoban_t *sokoban, int *retry)
{
    if (check_win(sokoban) != 0) {
        endwin();
        return 0;
    } else {
        endwin();
        return 1;
    }
}

void game(sokoban_t *sokoban, int *retry)
{
    for (int i = 0; sokoban->map[i] != NULL; i++)
        mvwprintw(stdscr,
        stdscr->_maxy / 2 - (sokoban->nbrows / 2) + i,
        stdscr->_maxx / 2 - (sokoban->nbcol / 2), sokoban->map[i]);
    addch(' ');
    move(sokoban->poscursey, sokoban->poscursex);
    addch('P');
    move(sokoban->poscursey, sokoban->poscursex);
    int input = wgetch(stdscr);
    if (input == 32)
        *retry = 1;
    player_movement_input(sokoban, input);
}

int display(sokoban_t *sokoban)
{
    int retry = 0;
    while (retry == 0) {
        clear();
        actualise_size(sokoban);
        actualize_map(sokoban);
        if (check_win(sokoban) != 0 || check_lose(sokoban) != 0) {
            return print_win_lose(sokoban, &retry);
        } else if (sokoban->sizewiny < sokoban->nbrows ||
        sokoban->sizewiny < sokoban->nbcol) {
            mvwprintw(stdscr, stdscr->_maxy / 2,
            stdscr->_maxx / 2, "Wrong terminal size");
        } else {
            game(sokoban, &retry);
        }
        refresh();
    }
    if (retry == 1) {
        init_game(sokoban->filepath);
    }
}

int init_game(char *path)
{
    char *arraymap = open_file(path, count_int_read(path));
    sokoban_t sokoban;
    sokoban.filepath = path;
    sokoban.posx = 0;
    sokoban.posy = 0;
    if (check_map(arraymap, &sokoban)) return 84;
    sokoban.nbrows = get_rows(arraymap);
    sokoban.nbcol = get_cols(arraymap);
    arraymap = del_player(arraymap);
    sokoban.map = my_strtwa(arraymap, "\n");
    sokoban.mapcpy = my_strtwa(arraymap, "\n");
    initscr();
    keypad(stdscr, TRUE);
    sokoban.sizewinx = stdscr->_maxx;
    sokoban.sizewiny = stdscr->_maxy;
    sokoban.poscursex = sokoban.posx + stdscr->_maxx / 2 - (sokoban.nbcol / 2);
    sokoban.poscursey = sokoban.posy +
    stdscr->_maxy / 2 - (sokoban.nbrows / 2);
    return display(&sokoban);
}
