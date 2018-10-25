/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** task11
*/

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	my_str_isnum(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0') {
		if (is_num(str[i]) == 0)
			return (0);
		else
			i = i + 1;
	}
	return (1);
}
