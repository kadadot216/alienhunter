#include "hunter.h"

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
	new->texts[SCORE] = text_set_position(new->texts[SCORE], win->mode.width - 180, win->mode.height - 50);
	new->texts[LIVES] = text_set_position(new->texts[LIVES], 0, win->mode.height - 50);
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
