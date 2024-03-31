/*
** EPITECH PROJECT, 2023
** pf
** File description:
** Pointer on function
*/

#include <stdarg.h>
#include "../include/hashtable.h"

int my_character(va_list list)
{
    my_putchar(va_arg(list, int));
    return (1);
}

int my_percent(va_list list)
{
    my_putchar('%');
    return (1);
}

int my_string(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
    return (my_strlen(str));
}

int my_number(va_list list)
{
    int nb = va_arg(list, int);

    my_put_nbr(nb);
    return (my_intlen(nb));
}
