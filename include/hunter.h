#ifndef __MY_HUNTER_H__
#define __MY_HUNTER_H__

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

//fenetre du jeu

int     my_strlen(char const *str);
char    *my_strdup(char const *src);
int     rand_min_max(int min, int max);
char    *my_strcat(char *dest, char *const src);
void	my_revstr(char *str);
char	*my_itoa(int nb, char *buf);
void    my_memset(char *str, char c, int size);
void	my_putstr(char *const str);


#define WIN_TITLE   ("Hunter")
#define BIT_DEPTH   (32)

typedef struct s_window {
    char    *title;
    sfRenderWindow  *render;
    sfVideoMode mode;
    sfEvent event;
}   window_t;

window_t    *window_create(int height, int width);
window_t    *window_destroy(window_t *this);

//constante des assets

#define FONT_PATH   ("./assets/font.ttf")
#define CHAR_SIZE   (40)

#define BG_PATH     ("./assets/galaxy.jpg")

#define ALIEN_PATH ("./assets/alien.png")
#define ALIEN_W     (220)
#define ALIEN_H     (230)

#define PAUSE_PATH  ("./assets/pause.png")
#define PAUSE_W     (256)
#define PAUSE_H     (256)

typedef  struct	s_hitbox {
	int	top;
	int	right;
	int	down;
	int	left;
}	hitbox_t;

typedef enum	asset_status {
    VISIBLE,
    HIDDEN
}	astatus_t;

typedef  struct  s_asset {
    sfTexture   *tex;
    sfSprite    *sp;
    sfIntRect    size;
    hitbox_t	hb; 
    astatus_t	status;
}   asset_t;

enum    asset_id{
    BG,
    ALIEN,
    SCOPE,
    ASSET_SIZE
};

enum    text_id {
    SCORE,
    LIVES,
    TEXT_SIZE,
};

typedef struct  s_text {
    char    *prefix;
    sfText  *display;
    int data;
}   text_t;

text_t  *text_new(sfFont *font);
text_t	*text_set_prefix(text_t *this, char *const prefix);
text_t	*text_set_position(text_t *this, int x, int y);
text_t  *text_destroy(text_t *this);
void    text_set_string(text_t *this, char *buffer);

typedef struct  s_col {
    sfFont	*font;
    asset_t *assets[ASSET_SIZE];
    text_t  *texts[TEXT_SIZE];
}   col_t;

asset_t *asset_new(int width, int height, char *const path, int full);
asset_t *asset_new_alien(void);
asset_t *asset_new_pause(void);
asset_t *asset_new_bg(window_t *win);
asset_t *asset_destroy(asset_t *this);
void	asset_update_position(asset_t *this);
void	asset_set_position(asset_t *this, int x, int y);

void    alien_set_position(asset_t *, window_t *);
void	show_alien(asset_t *alien, window_t *win);
void	hide_alien(asset_t *alien);
void	move_alien(asset_t *this, float speed);
int	alien_outside_screen(asset_t *alien, window_t *win);

#define NB_LIVES        (3)

#define SCOPE_SIZE      (64)

#define SCOPE_PATH      ("./assets/scope.png")

typedef struct  s_player {
    int *lives;
    int *score;
    asset_t *scope;
}   player_t;

asset_t *asset_new_scope(void);
player_t	*player_update_mouse_pos(player_t *player, sfMouseMoveEvent *evt);
player_t    *player_init(int lives, col_t *col);
int	in_range(hitbox_t *scope, hitbox_t *alien);
void	player_hit(player_t *player, asset_t *alien);
float	speed_from_score(int score);
player_t	*player_destroy(player_t *this);

//TIMER
float	timer_get_time(sfClock *clock);
void	timer_restart(sfClock *clock);
int	timer_is_synced(sfClock *clock);

// EVENTS
void	poll_events(window_t *win, player_t *player, col_t *col);
void	dispatch(window_t *win, col_t *col);
void	update_events(window_t *win, col_t *col, sfClock *clock);

// COL ASSETS
col_t	*init_assets(window_t *win);
col_t	*destroy_assets(col_t *col);

// MUSIC

#define TRACK_PATH  ("./assets/batrolld.ogg")

#endif
