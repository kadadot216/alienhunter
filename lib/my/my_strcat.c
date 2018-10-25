/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** task02
*/

char	*my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	j = my_strlen(dest);

	while (src[i] != '\0') {
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
