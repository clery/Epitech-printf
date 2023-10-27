/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include "utils.h"

int handle_double(va_list *ap, flag_opt_t opt) {
    int res;
    double nb;

    nb = va_arg(*ap, double);
    res = my_putnbr(nb);
    if (nb < 0)
        nb *= -1;
    if (opt.precision > 0) {
        res += write(1, ".", 1);
        nb -= (long)nb;
        while (opt.precision > 0) {
            nb *= 10;
            res += my_putnbr(nb);
            nb -= (long)nb;
            opt.precision--;
        }
    }
    return res;
}