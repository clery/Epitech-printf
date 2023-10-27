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

static const flag_t flagmap[] = {
    {'%', handle_modulo},
    {'c', handle_character},
    {'d', handle_integer},
    {'f', handle_double},
    {'i', handle_integer},
    {'o', handle_oct},
    {'s', handle_string},
    {'u', handle_unsigned},
    {'X', handle_hex_caps},
    {'x', handle_hex},
};

static int find_next_flag(char const *fmt) {
    int i = 0;

    while (fmt && fmt[i] && fmt[i] != flag)
        ++i;
    return i;
}

static convert_func_t conversion_func(char flag) {
    for (size_t i = 0; i < sizeof(flagmap) / sizeof(*flagmap); ++i) {
        if (flagmap[i].flag == flag)
            return flagmap[i].ptr;
    }
    return NULL;
}

static int parse_options(char const **fmt, va_list *ap, flag_opt_t *opt) {
    int i = 0;

    (void)ap;
    while (*fmt[i] && !conversion_func(*fmt[i]))
        switch (*fmt[i++]) {
            case ' ':
                opt->space_plus |= SPACE;
                break;
            case '+':
                opt->space_plus |= PLUS;
                break;
            case '-':
                opt->zero_minus |= MINUS;
                break;
            case '0':
                opt->zero_minus |= ZERO;
                break;
        }
    if (opt->precision == -1)
        opt->precision = 6;
    return i;
}

static int handle_flag(char const **fmt, va_list *ap) {
    size_t i = 0;
    int ret = 0;
    flag_opt_t opt = {.precision=-1, .length=-1};
    convert_func_t f;

    if ((*fmt)[i] == flag) {
        parse_options(fmt, ap, &opt);
        ++i;
        f = conversion_func((*fmt)[i]);
        if (f) {
            ret += f(ap, opt);
            ++i;
        }
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
        next_flag = handle_flag(&fmt, &ap);
        ret += next_flag;
        if (next_flag == 0 && *fmt) {
            next_flag = find_next_flag(fmt + 1);
            ret += write(1, fmt, next_flag + 1);
            fmt += next_flag == 0 ? 0 : next_flag + 1;
        }
    }
    va_end(ap);
    return (ret);
}