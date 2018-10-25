/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** task03
*/

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i = 0;
	int	j = my_strlen(dest);

	while (src[i] != '\0' && i < nb) {
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
