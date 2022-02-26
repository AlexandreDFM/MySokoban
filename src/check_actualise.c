/*
** EPITECH PROJECT, 2022
** actualise
** File description:
** Function to actualise
*/

#include "sokoban.h"

int check_actualize_map(sokoban_t *sokoban, int y, int x)
{
    if (sokoban->mapcpy[x][y] == 'O' && sokoban->map[x][y] == ' ')
        sokoban->map[x][y] = 'O';
}

int check_check_win(sokoban_t *sokoban, int y, int x, int *countero)
{
    if (sokoban->map[y][x] == 'O')
        *countero += 1;
}
