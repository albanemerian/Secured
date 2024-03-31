/*
** EPITECH PROJECT, 2023
** my
** File description:
** CPool lib
*/

#include <stdarg.h>

#pragma once

#ifndef MY_H_
    #define MY_H_

typedef struct printf_s {
    char flags;
    int(*pf)(va_list);
} printf_t;


void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_unsigned_nbr(unsigned int n);
char *my_strdup(char const *src);
void my_positive_nbr(int nb);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_compute_power_rec(int nb, int p);
int my_intlen(int nb);
int mini_printf(const char *format, ...);
int my_character(va_list list);
int my_percent(va_list list);
int my_string(va_list list);
int my_number(va_list list);

#endif /*!MY_H_*/
