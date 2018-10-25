/*
** EPITECH PROJECT, 2017
** strlowcase.c
** File description:
** task08
*/

char *my_strlowcase(char *str)
{
	int	i;

	while (str[i]) {
		str[i] +=32;
		i++;
	}
	return (str);
}
