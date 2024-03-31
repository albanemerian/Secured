/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** Version of printf with flag d, i, c, s and %
*/

#include <stdarg.h>
#include "../include/my.h"

static printf_t FLAGS_FUNCTION[] = {{'%', &my_percent},
    {'c', &my_character}, {'s', &my_string}, {'d', &my_number},
    {'i', &my_number}};


static int disp_arg(char c, va_list list)
{
    int result = 0;

    for (int i = 0; FLAGS_FUNCTION[i].flags != '\0'; i++) {
        if (FLAGS_FUNCTION[i].flags == c)
            result += FLAGS_FUNCTION[i].pf(list);
    }
    return (result);
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int result = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i + 1] != '\0' && format[i] == '%') {
            i++;
            result += disp_arg(format[i], list);
        } else {
            my_putchar(format[i]);
            result++;
        }
    }
    va_end(list);
    return (result);
}
