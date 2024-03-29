/*
** EPITECH PROJECT, 2022
** movement
** File description:
** Funciton to manage movement
*/

#include "sokoban.h"

void move_up(sokoban_t *sokoban, int x, int y)
{
    if (sokoban->map[sokoban->posy - 1][sokoban->posx] == 'X'
    && sokoban->map[sokoban->posy - 2][sokoban->posx] != '#'
    && sokoban->map[sokoban->posy - 2][sokoban->posx] != 'X') {
        y -= 1;
        y = min_y(y);
        sokoban->poscursey = y;
        sokoban->posy -= 1;
        sokoban->map[sokoban->posy][sokoban->posx] = ' ';
        sokoban->map[sokoban->posy - 1][sokoban->posx] = 'X';
    } else if (sokoban->map[sokoban->posy - 1][sokoban->posx] != 'X') {
        y -= 1;
        y = min_y(y);
        sokoban->poscursey = y;
        sokoban->posy -= 1;
    }
}

void move_down(sokoban_t *sokoban, int x, int y)
{
    if (sokoban->map[sokoban->posy + 1][sokoban->posx] == 'X'
    && sokoban->map[sokoban->posy + 2][sokoban->posx] != '#'
    && sokoban->map[sokoban->posy + 2][sokoban->posx] != 'X') {
        y += 1;
        y = max_y(y);
        sokoban->poscursey = y;
        sokoban->posy += 1;
        sokoban->map[sokoban->posy][sokoban->posx] = ' ';
        sokoban->map[sokoban->posy + 1][sokoban->posx] = 'X';
    } else if (sokoban->map[sokoban->posy + 1][sokoban->posx] != 'X') {
        y += 1;
        y = max_y(y);
        sokoban->poscursey = y;
        sokoban->posy += 1;
    }
}

void move_left(sokoban_t *sokoban, int x, int y)
{
    if (sokoban->map[sokoban->posy][sokoban->posx - 1] == 'X'
    && sokoban->map[sokoban->posy][sokoban->posx - 2] != '#'
    && sokoban->map[sokoban->posy][sokoban->posx - 2] != 'X') {
        x -= 1;
        x = min_x(x);
        sokoban->poscursex = x;
        sokoban->posx -= 1;
        sokoban->map[sokoban->posy][sokoban->posx] = ' ';
        sokoban->map[sokoban->posy][sokoban->posx - 1] = 'X';
    } else if (sokoban->map[sokoban->posy][sokoban->posx - 1] != 'X') {
        x -= 1;
        x = min_x(x);
        sokoban->poscursex = x;
        sokoban->posx -= 1;
    }
}

void move_right(sokoban_t *sokoban, int x, int y)
{
    if (sokoban->map[sokoban->posy][sokoban->posx + 1] == 'X'
    && sokoban->map[sokoban->posy][sokoban->posx + 2] != '#'
    && sokoban->map[sokoban->posy][sokoban->posx + 2] != 'X') {
        x += 1;
        x = max_x(x);
        sokoban->poscursex = x;
        sokoban->posx += 1;
        sokoban->map[sokoban->posy][sokoban->posx] = ' ';
        sokoban->map[sokoban->posy][sokoban->posx + 1] = 'X';
    } else if (sokoban->map[sokoban->posy][sokoban->posx + 1] != 'X') {
        x += 1;
        x = max_x(x);
        sokoban->poscursex = x;
        sokoban->posx += 1;
    }
}

void player_movement_input(sokoban_t *sokoban, int input)
{
    if (input == KEY_UP &&
    sokoban->map[sokoban->posy - 1][sokoban->posx] != '#')
        move_up(sokoban, getcurx(stdscr), getcury(stdscr));
    if (input == KEY_DOWN &&
    sokoban->map[sokoban->posy + 1][sokoban->posx] != '#')
        move_down(sokoban, getcurx(stdscr), getcury(stdscr));
    if (input == KEY_LEFT &&
    sokoban->map[sokoban->posy][sokoban->posx - 1] != '#')
        move_left(sokoban, getcurx(stdscr), getcury(stdscr));
    if (input == KEY_RIGHT &&
    sokoban->map[sokoban->posy][sokoban->posx + 1] != '#')
        move_right(sokoban, getcurx(stdscr), getcury(stdscr));
}
