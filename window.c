/*
** EPITECH PROJECT, 2018
** window
** File description:
** hunter
*/

#include "my_hunter.h"

window_t    *window_create(int width, int height)
{
    window_t    *new = malloc(sizeof(*new));

    if (new == NULL) {
        return(NULL);
    }
    new->title = my_strdup(WIN_TITLE);
    new->mode.width = width;
    new->mode.height = height;
    new->mode.bitsPerPixel = 32;
    new->render = sfRenderWindow_create(new->mode, new->title, sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(new->render, sfFalse);
    return (new);
}

window_t    *window_destroy(window_t *this)
{
    sfRenderWindow_destroy(this->render);
    this->mode.width = 0;
    this->mode.height = 0;
    this->mode.bitsPerPixel = 0;
    free(this->title);
    free(this);
    this = NULL;
    return (this);
}
