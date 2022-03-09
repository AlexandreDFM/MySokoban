/*
** EPITECH PROJECT, 2022
** player
** File description:
** Get player
*/

#include "sokoban.h"

void player_pos2(sokoban_t *sokoban, char **map, int y, int x)
{
    if (map[y][x] == 'P') {
        sokoban->posy = y;
        sokoban->posx = x;
    }
}

void player_pos(sokoban_t *sokoban, char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            player_pos2(sokoban, map, y, x);
        }
    }
}

char **del_player2(char **map, int y, int x)
{
    if (map[y][x] == 'P') {
        map[y][x] = ' ';
    }
    return map;
}

char **del_player(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            map = del_player2(map, y, x);
        }
    }
    return map;
}

void check_player(sokoban_t *sokoban)
{
    player_pos(sokoban, sokoban->map);
    del_player(sokoban->map);
    del_player(sokoban->mapcpy);
}
