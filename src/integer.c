/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stdarg.h>
#include <unistd.h>

static int my_putnbr(int n) {
    int ret = 0;
    char c;

    if (n < 0) {
        n *= -1;
        ret += write(1, "-", 1);
    }
    if (n > 10)
        ret += my_putnbr(n / 10);
    c = n % 10 + '0';
    return ret + write(1, &c, 1);
}

int handle_integer(va_list *ap) {
    int i;

    i = va_arg(*ap, int);
    return my_putnbr(i);
}