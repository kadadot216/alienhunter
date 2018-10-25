/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** task12
*/


int	my_str_islower(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (is_lower(str[i]) == 0)
			return (0);
		else
			i = i + 1;
	}
	return (1);
}
