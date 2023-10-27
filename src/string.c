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

int handle_string(va_list *ap, flag_opt_t __attribute__ ((unused))opt) {
    char *s;

    s = va_arg(*ap, char *);
    return write(1, s, my_strlen(s));
}