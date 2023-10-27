/*
** EPITECH PROJECT, 2023
** printf
** File description:
** printf
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>

enum flag_e {
    ZERO = 1 << 1,
    MINUS = 1 << 2,
    SPACE = 1 << 3,
    PLUS = 1 << 4,
};

typedef struct flag_opt_s
{
    int length;
    int precision;
    int zero_minus;
    int space_plus;
} flag_opt_t;

typedef int (*convert_func_t)(va_list *, flag_opt_t);

typedef struct flag_s
{
    char flag;
    convert_func_t ptr;
} flag_t;

int my_printf(char const *fmt, ...);
int handle_modulo(va_list *, flag_opt_t);
int handle_character(va_list *, flag_opt_t);
int handle_string(va_list *, flag_opt_t);
int handle_integer(va_list *, flag_opt_t);
int handle_double(va_list *, flag_opt_t);
int handle_hex(va_list *, flag_opt_t);
int handle_hex_caps(va_list *, flag_opt_t);
int handle_oct(va_list *ap, flag_opt_t);
int handle_unsigned(va_list *ap, flag_opt_t);

#endif /* !PRINTF_H_ */
