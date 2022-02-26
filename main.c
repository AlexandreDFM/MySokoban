/*
** EPITECH PROJECT, 2022
** main
** File description:
** Main of Sokoban
*/

#include "sokoban.h"

void my_manual(void)
{
    my_printf("%s", ""
    "USAGE\n"
    "     ./my_sokoban map\n"
    "DESCRIPTION\n"
    "     map file representing the warehouse map, containing '#' for walls,\n"
    "     'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_manual();
        return 0;
    }
    else if (argc == 2) {
        return init_game(argv[1]);
    }
}
