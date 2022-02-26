/*
** EPITECH PROJECT, 2022
** check_max_mov
** File description:
** Funciton check max_mov
*/

#include "sokoban.h"

int min_y(int y)
{
    if (y < 1)
        y = 1;
    return y;
}

int max_y(int y)
{
    if (y > stdscr->_maxy - 2)
        y = stdscr->_maxy - 2;
    return y;
}

int min_x(int x)
{
    if (x < 1)
        x = 1;
    return x;
}

int max_x(int x)
{
    if (x > stdscr->_maxx - 2)
        x = stdscr->_maxx - 2;
    return x;
}
