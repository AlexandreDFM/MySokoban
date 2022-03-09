/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** Header of Sokoban
*/

#include "my.h"
#include "printf.h"
#include "ncurses.h"
#include <sys/stat.h>
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

int min_y(int y);
int max_y(int y);
int min_x(int x);
int max_x(int x);
char *open_file(char *mappath, int size_of_read);
int check_actualize_map(sokoban_t *sokoban, int y, int x);
int check_check_win(sokoban_t *sokoban, int y, int x, int *countero);
int count_int_read(char *mappath);
int get_rows(char *map);
int get_cols(char *map);
int init_game(char *path);
void check_player(sokoban_t *sokoban);
char **del_player(char **map);
void player_pos(sokoban_t *sokoban, char **map);
int check_map(char *map, sokoban_t *sokoban);
int actualise_size(sokoban_t *sokoban);
int actualize_map(sokoban_t *sokoban);
int check_win(sokoban_t *sokoban);
int check_lose(sokoban_t *sokoban);
int display(sokoban_t *sokoban);
void player_movement_input(sokoban_t *sokoban, int input);
char **my_strtwa(char const *str, char *limit);

#endif
