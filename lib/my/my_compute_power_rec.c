/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** task04
*/

int	my_compute_power_rec(int nb, int d)
{
	if (d == 0)
		return (1);
	else if (d < 0)
		return (0);
	else
		return (my_compute_power_rec(nb, d - 1) * nb);
}
