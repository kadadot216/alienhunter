#include "my_hunter.h"

void	my_swap(char *a, char *b)
{
	char	tmp = *a;

	*a = *b;
	*b = tmp;
}

void	my_revstr(char *str)
{
	int	i = 0;
	int	j = (my_strlen(str) - 1);

	while (i < j) {
		my_swap(&str[i], &str[j]);
		i++;
		j--;
	}
}
