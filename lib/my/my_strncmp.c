/*
** EPITECH PROJECT, 2017
** strncmp
** File description:
** task06 
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;

	return (s1[i] - s2[i]);

}