#include "hunter.h"

sfMusic *music_create(void)
{
    sfMusic *new = sfMusic_createFromFile(TRACK_PATH);

    //sfMusic_setVolume(new, 0.4);
    sfMusic_setLoop(new, sfTrue);
    return (new);
}

sfMusic *music_destroy(sfMusic *this)
{
    sfMusic_stop(this);
    sfMusic_destroy(this);
    this = NULL;
    return (this);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    window_t	*win = window_create(800, 600);
    col_t	*col = init_assets(win);
    player_t	*player = player_init(3, col);
    sfClock	*clock = sfClock_create();
    sfMusic *track = music_create();

    srand(time(NULL));
    alien_set_position(col->assets[ALIEN], win);
    sfMusic_play(track);
    while (sfRenderWindow_isOpen(win->render) && *player->lives > 0) {
	    poll_events(win, player, col);
	    update_events(win, col, clock);
	    dispatch(win, col);
    }
    win = window_destroy(win);
    col = destroy_assets(col);
    player = player_destroy(player);
    sfClock_destroy(clock);
    track = music_destroy(track);
    my_putstr("Game Over :)\n");
    return (0);
}
