/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** task10
*/

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	my_str_isalpha(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0') {
		if (is_alpha(str[i]) == 0)
			return (0);
		else
			i = i + 1;
	}
	return (1);
}
