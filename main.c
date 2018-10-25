


#include "my_hunter.h"

void	poll_events(window_t *win, player_t *player, col_t *col)
{
	while(sfRenderWindow_pollEvent(win->render, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->render);
		else if (win->event.type == sfEvtMouseMoved)
			player = player_update_mouse_pos(player, &win->event.mouseMove);
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

col_t	*init_assets(window_t *win)
{
	col_t	*new = malloc(sizeof(*new));

	new->font = sfFont_createFromFile(FONT_PATH);
	new->assets[BG] = asset_new_bg(win);
	new->assets[ALIEN] = asset_new_alien();
	new->assets[SCOPE] = asset_new_scope();
	new->texts[SCORE] = text_new(new->font);
	new->texts[LIVES] = text_new(new->font);
	new->texts[SCORE] = text_set_prefix(new->texts[SCORE], "Score: ");
	new->texts[LIVES] = text_set_prefix(new->texts[LIVES], "Lives: ");
	new->texts[SCORE] = text_set_position(new->texts[SCORE], 500, 400);
	new->texts[LIVES] = text_set_position(new->texts[LIVES], 200, 300);
	return (new);
}

col_t	*destroy_assets(col_t *col)
{
	col->assets[BG] = asset_destroy(col->assets[BG]);
	col->assets[ALIEN] = asset_destroy(col->assets[ALIEN]);
	col->assets[SCOPE] = asset_destroy(col->assets[SCOPE]);
	col->texts[LIVES] = text_destroy(col->texts[LIVES]);
	col->texts[SCORE] = text_destroy(col->texts[SCORE]);
	sfFont_destroy(col->font);
	free(col);
	return (col);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    window_t	*win = window_create(800, 600);
    col_t	*col = init_assets(win);
    player_t	*player = player_init(3, col);

    srand(time(NULL));
    alien_set_position(col->assets[ALIEN], win);
    while (sfRenderWindow_isOpen(win->render)) {
	    poll_events(win, player, col);
	    dispatch(win, col);
    }
    win = window_destroy(win);
    col = destroy_assets(col);
    return (0);
}
