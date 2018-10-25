/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** task13
*/

int	my_str_isupper(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0') {
		if (is_upper(str[i]) == 0)
			return (0);
		else
			i = i + 1;
	}
	return (1);
}
