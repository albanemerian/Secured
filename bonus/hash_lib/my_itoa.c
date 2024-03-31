/*
** EPITECH PROJECT, 2023
** my_itoa
** File description:
** Turn an int into a char *
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_itoa(int nb)
{
    char *numbers = "0123456789";
    char *str = malloc(sizeof(char) * (my_intlen(nb) + 1));
    int i = my_intlen(nb);

    str[i] = '\0';
    i--;
    while (i >= 0) {
        str[i] = numbers[nb % 10];
        nb /= 10;
        i--;
    }
    return (str);
}
