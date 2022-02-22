/*
** EPITECH PROJECT, 2022
** actualise
** File description:
** Function to actualise
*/

#include "sokoban.h"

int actualise_size(sokoban_t *sokoban)
{
    if (sokoban->sizewinx != stdscr->_maxx) {
        sokoban->sizewinx = stdscr->_maxx;
        sokoban->poscursex = sokoban->posx +
        stdscr->_maxx / 2 - (sokoban->nbcol / 2);
    }
    if (sokoban->sizewiny != stdscr->_maxy) {
        sokoban->sizewiny = stdscr->_maxy;
        sokoban->poscursey = sokoban->posy +
        stdscr->_maxy / 2 - (sokoban->nbrows / 2);
    }
}

int actualize_map(sokoban_t *sokoban)
{
    for (int x = 0; sokoban->mapcpy[x] != NULL; x++) {
        for (int y = 0; sokoban->mapcpy[x][y] != '\0'; y++) {
            if (sokoban->mapcpy[x][y] == 'O' && sokoban->map[x][y] == ' ')
                sokoban->map[x][y] = 'O';
        }
    }
}

int check_win(sokoban_t *sokoban)
{
    int counterO = 0;
    for (int y = 0; sokoban->map[y] != NULL; y++) {
        for (int x = 0; sokoban->map[y][x] != '\0'; x++) {
            if (sokoban->map[y][x] == 'O') {
                counterO += 1;
            }
        }
    }
    if (counterO == 0) {
        return 1;
    }
    return 0;
}

int check_lose2(sokoban_t *sokoban, int x, int y, int *counter)
{
    if (sokoban->map[y][x] == 'X') {
        if (sokoban->map[y + 1][x] == '#')
            *counter += 1;
        if (sokoban->map[y - 1][x] == '#')
            *counter += 1;
        if (sokoban->map[y][x + 1] == '#')
            *counter += 1;
        if (sokoban->map[y][x - 1] == '#')
            *counter += 1;
        return 1;
    }
    return 0;
}

int check_lose(sokoban_t *sokoban)
{
    int counter = 0;
    int counterx = 0;
    for (int y = 0; sokoban->map[y] != NULL; y++) {
        for (int x = 0; sokoban->map[y][x]; x++) {
            counterx += check_lose2(sokoban, x, y, &counter);
        }
    }
    if (counter == 2 * counterx)
        return counter;
    return 0;
}
