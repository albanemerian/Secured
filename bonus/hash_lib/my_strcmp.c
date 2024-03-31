/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare 2 strings
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (*s1 - *s2 < 0)
        return (-1);
    if (*s1 - *s2 > 0)
        return (1);
    return (0);
}
