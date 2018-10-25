/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** task01
*/

#include <unistd.h>

void	my_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
