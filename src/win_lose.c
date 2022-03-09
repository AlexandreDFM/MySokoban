/*
** EPITECH PROJECT, 2022
** win_lose
** File description:
** Function to win_lose
*/

#include "sokoban.h"

int win(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        mvwprintw(stdscr,
        stdscr->_maxy / 2 - (sokoban->nbrows / 2) + i,
        stdscr->_maxx / 2 - (sokoban->nbcol / 2), sokoban->map[i]);
    }
    addch(' ');
    move(sokoban->poscursey, sokoban->poscursex);
    addch('P');
    move(sokoban->poscursey, sokoban->poscursex);
    refresh();
    endwin();
    return 0;
}

int lose(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        mvwprintw(stdscr,
        stdscr->_maxy / 2 - (sokoban->nbrows / 2) + i,
        stdscr->_maxx / 2 - (sokoban->nbcol / 2), sokoban->map[i]);
    }
    addch(' ');
    move(sokoban->poscursey, sokoban->poscursex);
    addch('P');
    move(sokoban->poscursey, sokoban->poscursex);
    refresh();
    endwin();
    return 1;
}

int print_win_lose(sokoban_t *sokoban, int *retry)
{
    if (check_win(sokoban) != 0) {
        return win(sokoban);
    } else {
        return lose(sokoban);
    }
}
