/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** Header of Sokoban
*/

#include "my.h"
#include "printf.h"
#include "ncurses.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct sokoban {
    int sizewinx;
    int sizewiny;
    int posx;
    int posy;
    int nbrows;
    int nbcol;
    int poscursex;
    int poscursey;
    char *filepath;
    char **map;
    char **mapcpy;
}sokoban_t;

#ifndef SOKOBAN
    #define SOKOBAN

char *open_file(char *mappath, int size_of_read);
int count_int_read(char *mappath);
int get_rows(char *map);
int get_cols(char *map);
int init_game(char *path);
int check_map(char *map, sokoban_t *sokoban);
int actualise_size(sokoban_t *sokoban);
int actualize_map(sokoban_t *sokoban);
int check_win(sokoban_t *sokoban);
int check_lose(sokoban_t *sokoban);
void display(sokoban_t *sokoban);
void player_movement_input(sokoban_t *sokoban, int input);
char **my_str_to_word_array(char const *str);

#endif
