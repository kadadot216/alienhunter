/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** CPool_Day03_2017
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
