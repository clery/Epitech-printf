/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

int handle_modulo(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    (void)ap;
    return write(1, "%", 1);
}

int handle_character(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    char c;

    c = va_arg(*ap, int);
    return write(1, &c, 1);
}