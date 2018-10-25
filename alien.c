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
    sfVector2f	position = {0, 0};
    float   pos_x = win->mode.width - this->size.width;
    float   pos_y = win->mode.height - this->size.height;

    this->hb.left = pos_x;
    this->hb.top = rand_min_max(0, pos_y);
    position.y = this->hb.top;
    position.x = this->hb.left;
    sfSprite_setPosition(this->sp, position);
}
