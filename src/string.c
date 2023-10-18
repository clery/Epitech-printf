/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stdarg.h>
#include <unistd.h>

static int my_strlen(char const *s) {
    int i = 0;

    while (s && s[i])
        ++i;
    return i;
}

int handle_string(va_list *ap) {
    char *s;

    s = va_arg(*ap, char *);
    return write(1, s, my_strlen(s));
}