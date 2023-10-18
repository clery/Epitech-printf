/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stdarg.h>
#include <unistd.h>

int handle_character(va_list *ap) {
    char c;

    c = va_arg(*ap, int);
    return write(1, &c, 1);
}