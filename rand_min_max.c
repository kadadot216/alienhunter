/*
** EPITECH PROJECT, 2018
** rand
** File description:
** hunter
*/

#include <stdlib.h>

int rand_min_max(int min, int max)
{
    int diff = ((max + 1) - min);

    return (min + (rand() % diff));
}
