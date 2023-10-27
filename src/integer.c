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

int handle_integer(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    int i;

    i = va_arg(*ap, int);
    return my_putnbr(i);
}

int handle_hex(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    unsigned i;

    i = va_arg(*ap, unsigned);
    return my_uputnbr_base(i, "0123456789abcdef");
}

int handle_hex_caps(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    unsigned int i;

    i = va_arg(*ap, unsigned);
    return my_uputnbr_base(i, "0123456789ABCDEF");
}

int handle_oct(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    unsigned int i;

    i = va_arg(*ap, unsigned);
    return my_uputnbr_base(i, "01234567");
}

int handle_unsigned(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    unsigned int i;

    i = va_arg(*ap, unsigned);
    return my_uputnbr_base(i, "0123456789");
}