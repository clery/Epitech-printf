/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_putnbr
*/

#include <unistd.h>
#include "utils.h"

int my_putnbr_base(int n, char const *base) {
    int ret = 0;
    char c;

    if (n < 0) {
        n *= -1;
        ret += write(1, "-", 1);
    }
    if (n >= my_strlen(base))
        ret += my_putnbr_base(n / my_strlen(base), base);
    c = base[n % my_strlen(base)];
    return ret + write(1, &c, 1);
}

int my_uputnbr_base(unsigned n, char const *base) {
    int ret = 0;
    char c;

    if (n >= (unsigned)my_strlen(base))
        ret += my_putnbr_base(n / my_strlen(base), base);
    c = base[n % my_strlen(base)];
    return ret + write(1, &c, 1);
}

int my_putnbr(int n) {
    return my_putnbr_base(n, "0123456789");
}
