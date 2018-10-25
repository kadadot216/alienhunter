/*
** EPITECH PROJECT, 2018
** player
** File description:
** hunter
*/

#include "my_hunter.h"

asset_t *asset_new_scope(void)
{
    sfVector2f	origin = {SCOPE_SIZE / 2, SCOPE_SIZE / 2};

    asset_t *scope = asset_new(SCOPE_SIZE, SCOPE_SIZE, SCOPE_PATH, 0);
    sfSprite_setOrigin(scope->sp, origin);
    return (scope);
}

player_t	*player_update_mouse_pos(player_t *player, sfMouseMoveEvent *evt)
{
    sfVector2f	position = { evt->x, evt->y };

    printf("x: %d, y: %d\n", evt->x, evt->y);
    sfSprite_setPosition(player->scope->sp, position);
    return (player);
}

player_t    *player_init(int lives, col_t *col)
{
    player_t    *new = malloc(sizeof(*new));

    new->lives = lives;
    new->score = 0;
    new->scope = col->assets[SCOPE];
    return (new);
}
    