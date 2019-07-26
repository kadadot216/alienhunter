#include "hunter.h"

char    *my_itoa(int nb, char *buf)
{
    int	i = 0;

    if (nb == 0) {
        buf[i] = '0';
        return (buf);
    }
    while (nb > 0) {
        buf[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    my_revstr(buf);
    buf[i] = '\0';
    return (buf);
}
