
#include "hunter.h"

int	in_range(hitbox_t *scope, hitbox_t *alien)
{
	if (scope->top > alien->top && scope->down < alien->down &&
		scope->left > alien->left && scope->right < alien->right)
		return (1);
	else
		return (0);
}

void	show_alien(asset_t *alien, window_t *win)
{
    alien_set_position(alien, win);
    alien->status = VISIBLE;
}

float	speed_from_score(int score)
{
	return (0.4 + (score * 0.02));
}

void	hide_alien(asset_t *alien)
{
	sfIntRect	hidden = {0, 0, 0, 0};

	asset_set_position(alien, -1, -1);
	sfSprite_setTextureRect(alien->sp, hidden);
	alien->status = HIDDEN;
}

#include <stdio.h>
void	player_hit(player_t *player, asset_t *alien)
{
	if (in_range(&player->scope->hb, &alien->hb) == 1) {
		printf("HIT\n");
		*player->score += 1;
		hide_alien(alien);
	} else {
		printf("MISS\n");
		*player->lives -= 1;
	}
}
