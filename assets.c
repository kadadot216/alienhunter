/*
** EPITECH PROJECT, 2018
** assets
** File description:
** hunter
*/

#include "my_hunter.h"

asset_t *asset_new(int width, int height, char *const path, int full)
{
    asset_t *new = malloc(sizeof(*new));

    if (new == NULL) {
        return (NULL);
    }
    new->size.height = height;
    new->size.width = width;
    new->size.top = 0;
    new->size.left = 0;
    new->hb.top = 0;
    new->hb.left = 0;
    new->hb.right = 0;
    new->hb.down = 0;
    if (full)
        new->tex = sfTexture_createFromFile(path, NULL);
    else
        new->tex = sfTexture_createFromFile(path, &new->size);
    new->sp = sfSprite_create();
    sfSprite_setTexture(new->sp, new->tex, sfFalse);
    return (new);
}

asset_t *asset_new_alien(void)
{
    asset_t *alien = asset_new(ALIEN_W, ALIEN_H, ALIEN_PATH, 0);
    return (alien);
}

asset_t *asset_new_pause(void)
{
    asset_t *pause = asset_new(PAUSE_W, PAUSE_H, PAUSE_PATH, 0);
    return (pause);
}

asset_t *asset_new_bg(window_t *win)
{
    asset_t *bg = asset_new(win->mode.width, win->mode.height, BG_PATH, 1);
    return (bg);
}

#include <stdio.h>
void	asset_update_position(asset_t *this)
{
	sfVector2f	curr_pos = sfSprite_getPosition(this->sp);

	this->hb.top = curr_pos.y;
	this->hb.left = curr_pos.x;
	this->hb.right = curr_pos.x + this->size.width;
	this->hb.down = curr_pos.y + this->size.height;
	printf("{top: %d, right: %d, left: %d, down: %d}\n", this->hb.top,
		this->hb.right, this->hb.left, this->hb.down);
}

asset_t *asset_destroy(asset_t *this)
{
    this->size.top = 0;
    this->size.left = 0;
    this->size.height = 0;
    this->size.width = 0;
    this->hb.top = 0;
    this->hb.left = 0;
    this->hb.right = 0;
    this->hb.down = 0;
    sfSprite_destroy(this->sp);
    this->sp = NULL;
    sfTexture_destroy(this->tex);
    this->tex = NULL;
    free(this);
    this = NULL;
    return (this);
}
