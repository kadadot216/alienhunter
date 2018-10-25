/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** lib
*/

#include <stdlib.h>
#include <string.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char    *my_strdup(char *const src)
{
    char *dest = NULL;
    int lenght = 0;
    int i = 0;

    if (src == NULL) {
        return (NULL);
    }
    lenght = my_strlen(src);
    dest = malloc(sizeof(char) *(lenght + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
