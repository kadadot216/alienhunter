/*
** EPITECH PROJECT, 2018
** move
** File description:
** hunter
*/

#include "my_hunter.h"
#include "time.h"

void    alien_set_position(asset_t *this, window_t  *win)
{
    float   pos_x = win->mode.width - this->size.width;
    float   pos_y= win->mode.height - this->size.height;

    this->pos.x = pos_x;
    this->pos.y = rand_min_max(0, pos_y);
    sfSprite_setPosition(this->sp, this->pos);
}
