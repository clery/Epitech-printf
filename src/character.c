/*
** EPITECH PROJECT, 2023
** printf
** File description:
** char
*/

#include <unistd.h>

static ssize_t my_putchar(char c)
{
    return write(1, &c, 1);
}
