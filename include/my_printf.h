/*
** EPITECH PROJECT, 2023
** printf
** File description:
** printf
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>

typedef struct flags_s
{
    char flag;
    int (*ptr)(va_list *);
} flags_t;

int my_printf(char const *fmt, ...);
int handle_character(va_list *);
int handle_string(va_list *);
int handle_integer(va_list *);

#endif /* !PRINTF_H_ */
