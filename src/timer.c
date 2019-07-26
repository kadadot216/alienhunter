#include "hunter.h"

float	timer_get_time(sfClock *clock)
{
	sfTime	elapsed = sfClock_getElapsedTime(clock);
	float	seconds = (elapsed.microseconds / 1000000.0);
	return (seconds);
}

int	timer_is_synced(sfClock *clock)
{
	int	seconds = ((int) timer_get_time(clock));

	return ((seconds > 0) && (seconds % 2 == 0));
}

void	timer_restart(sfClock *clock)
{
	int	seconds = ((int) timer_get_time(clock));

	if (timer_is_synced(clock) == 1) {
		sfClock_restart(clock);
	}
	seconds = 0;
}
