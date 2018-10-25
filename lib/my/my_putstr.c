/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

#include <unistd.h>

int	my_putstr(char	*str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
