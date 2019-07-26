#include "hunter.h"

void	poll_events(window_t *win, player_t *player, col_t *col)
{
	while(sfRenderWindow_pollEvent(win->render, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->render);
		else if (win->event.type == sfEvtMouseMoved)
			player = player_update_mouse_pos(player, &win->event.mouseMove);
		else if (win->event.type == sfEvtMouseButtonPressed && col->assets[ALIEN]->status == VISIBLE) {
			player_hit(player, col->assets[ALIEN]);
		}
	}
}

void	dispatch(window_t *win, col_t *col)
{
	int	i = 0;
	int	j = 0;
	char	buffer[40] = {'\0'};

	sfRenderWindow_clear(win->render, sfBlack);
	while (i < ASSET_SIZE) {
		sfRenderWindow_drawSprite(win->render, col->assets[i]->sp, NULL);
		i++;
	}
	while (j < TEXT_SIZE) {
		text_set_string(col->texts[j], buffer);
		sfRenderWindow_drawText(win->render, col->texts[j]->display, NULL);
		j++;
	}
	sfRenderWindow_display(win->render);
}
void	update_events(window_t *win, col_t *col, sfClock *clock)
{
    asset_t	*alien = col->assets[ALIEN];
    int		*score = &col->texts[SCORE]->data;

    move_alien(alien, speed_from_score(*score));
    asset_update_position(alien);
    if (timer_is_synced(clock) == 1 && alien->status == HIDDEN) {
	    timer_restart(clock);
	    show_alien(alien, win);
    }
    if (alien_outside_screen(alien, win)) {
	    show_alien(alien, win);
    }
}
