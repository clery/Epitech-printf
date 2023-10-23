/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <stddef.h>
#include <unistd.h>

static size_t my_strlen(char const *s) {
    size_t i = 0;

    while (s && s[i])
        ++i;
    return i;
}

static ssize_t my_putstr(const char *str)
{
    return write(1, str, my_strlen(str));
}
