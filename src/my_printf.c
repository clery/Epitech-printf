/*
** EPITECH PROJECT, 2023
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

static const char flag = '%';

static const flags_t flagmap[] = {
    {'c', handle_character},
    {'s', handle_string},
    {'d', handle_integer},
};

static int find_next_flag(char const *fmt) {
    int i = 0;

    while (fmt && fmt[i] && fmt[i] != flag)
        ++i;
    return i;
}

static int handle_flag(char const **fmt, va_list *ap) {
    size_t i = 0;
    size_t j = 0;
    int ret = 0;

    if ((*fmt)[i] == flag) {
        ++i;
        while (j < sizeof(flagmap) / sizeof(*flagmap)) {
            if ((*fmt)[i] == flagmap[j].flag) {
                ret = flagmap[j].ptr(ap);
                break;
            }
            ++j;
        }
        if (j < sizeof(flagmap) / sizeof(*flagmap))
            ++i;
    }
    *fmt += i;
    return ret;
}

int my_printf(char const *fmt, ...) {
    int next_flag = 0;
    va_list ap;
    int ret = 0;

    va_start(ap, fmt);
    while (*fmt) {
        next_flag = find_next_flag(fmt);
        ret += write(1, fmt, next_flag);
        fmt += next_flag;
        ret += handle_flag(&fmt, &ap);
    }
    va_end(ap);
    return (ret);
}