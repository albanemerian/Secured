/*
** EPITECH PROJECT, 2023
** test_my_strdup
** File description:
** Test for my_strdup function
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strdup(char const *src);

Test(my_strdup, Basic)
{
    cr_assert_str_eq(my_strdup("Hello"), strdup("Hello"));
}

Test(my_strdup, Void)
{
    cr_assert_str_eq(my_strdup(""), strdup(""));
}

Test(my_strdup, Long_string)
{
    cr_assert_str_eq(my_strdup("Hello World! Welcome to the Black Parade"), strdup("Hello World! Welcome to the Black Parade"));
}
