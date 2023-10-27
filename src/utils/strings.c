/*
** EPITECH PROJECT, 2023
** printf [Dev Container: C++ @ desktop-linux]
** File description:
** utils
*/

int my_strlen(char const *s) {
    int i = 0;

    while (s && s[i])
        ++i;
    return i;
}
