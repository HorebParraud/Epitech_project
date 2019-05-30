/*
** EPITECH PROJECT, 2019
** MATCHSTICK
** File description:
** gammes of life
*/

#include "my_match.h"

int game_run(match_stock_t *map)
{
    for (size_t good_job = -1; good_job; good_job = -1) {
        BREAK;
        P_TRN;
        while (good_job == -1)
            good_job = play_trn(map, NULL, NULL);
        if (good_job == -2)
            return 0;
        draw_map(map);
        if (map->total == 0) {
            LOSER;
            return 0;
        } BREAK;
        B_TRN;
        aiai_trn(map);
        draw_map(map);
        if (map->total == 0) {
            WINER;
            return 0;
        }
    } return 0;
}

void gene_map(match_stock_t *map)
{
    int nb_st = 1;

    map->total = 0;
    for (size_t i = 0; i < map->size; i++, nb_st += 2) {
        map->stik[i] = nb_st;
        map->total  += nb_st;
    } map->lnth = nb_st;
}

int argv_err(int ac, char **av)
{
    if (ac != 3)
        return 0x0;
    if ((my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) > 100)
        || my_getnbr(av[2]) <= 0)
        return 0x0;
    return 1;
}

int main(int ac, char **av)
{
    match_stock_t map;

    if (argv_err(ac, av) == 0x0)
        return 84;
    map.size = my_getnbr(av[1]);
    map.play = my_getnbr(av[2]);
    map.stik = malloc(sizeof(int) * map.size);
    gene_map(&map);
    draw_map(&map);
    game_run(&map);
    free(map.stik);
    return 0;
}
