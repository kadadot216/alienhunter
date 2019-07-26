#include "hunter.h"
#include "time.h"

void	move_alien(asset_t *this, float speed)
{
	sfVector2f	movement = {-speed, 0.0f};
	sfSprite_move(this->sp, movement);
}

int	alien_outside_screen(asset_t *alien, window_t *win)
{
	if (alien->hb.left < -1200) {
		return (1);
	} else {
		return (0);
	}
}

void    alien_set_position(asset_t *this, window_t *win)
{
    sfIntRect	show = {this->size.top, this->size.left, this->size.width, this->size.height};
    float   pos_x = win->mode.width;
    float   pos_y = win->mode.height - this->size.height;

    sfSprite_setTextureRect(this->sp, show);
    asset_set_position(this, pos_x, rand_min_max(0, pos_y));
}
