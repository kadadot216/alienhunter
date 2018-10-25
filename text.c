/*
** EPITECH PROJECT, 2018
** text
** File description:
** hunter
*/

#include "my_hunter.h"

text_t  *text_new(sfFont *font)
{
    text_t  *new = malloc(sizeof(*new));

    new->data = 0;
    new->prefix = NULL;
    new->display = sfText_create();
    sfText_setFont(new->display, font);
    sfText_setCharacterSize(new->display, CHAR_SIZE);
    sfText_setColor(new->display, sfWhite);
    return (new);
}

text_t	*text_set_prefix(text_t *this, char *const prefix)
{
    this->prefix = my_strdup(prefix);
    return (this);
}

text_t	*text_set_position(text_t *this, int x, int y)
{
    sfVector2f  position = {x, y};
	
    sfText_setPosition(this->display, position);
    return (this);
}

text_t  *text_destroy(text_t *this)
{
    this->data = 0;
    free(this->prefix);
    sfText_destroy(this->display);
    free(this);
    this = NULL;
    return (this);
}

void    text_set_string(text_t *this, char *buffer)
{
    int     length = my_strlen(this->prefix);

    my_strcat(buffer, this->prefix);
    my_itoa(this->data, &buffer[length]);
    sfText_setString(this->display, buffer);
    my_memset(buffer, 0, 40);
}
