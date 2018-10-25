/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for my_hunter
*/

#include "my_hunter.h"

int main(int ac, char **av)
{
    // On typecase en void pour lui dire de ne pas utiliser le paramètre
    (void)ac;
    (void)av;
    window_t    *win = window_create(800, 600);
    while (sfRenderWindow_isOpen(win->render)) {
        sfRenderWindow_clear(win->render, sfRed);
        while (sfRenderWindow_pollEvent(win->render, &win->event)) {
            if (win->event.type == sfEvtClosed)
                sfRenderWindow_close(win->render);
        }
        sfRenderWindow_display(win->render);
    }
    win = window_destroy(win);
    return (0);
}
