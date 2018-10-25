/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** task07
*/

int	is_lower(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char	*my_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') {

		if (is_lower(str[i]) == 1)
			str[i] = str[i] - 32;
		i = i + 1;
	}
	return (str);
}
