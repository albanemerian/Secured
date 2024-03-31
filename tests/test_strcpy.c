/*
** EPITECH PROJECT, 2023
** test_my_strcpy
** File description:
** Tests for strcpy function
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, Basic)
{
    char *dest = malloc(sizeof(char) * (10 + 1));
    char *src = "Basic_test";

    my_strcpy(dest, src);
    strcpy(dest, src);
    cr_assert_str_eq(my_strcpy(dest, src), strcpy(dest, src));
}

Test(my_strcpy, Void)
{
    char *dest = malloc(sizeof(char) * (0 + 1));
    char *src = "";

    my_strcpy(dest, src);
    strcpy(dest, src);
    cr_assert_str_eq(my_strcpy(dest, src), strcpy(dest, src));
}

Test(my_strcpy, One_char)
{
    char *dest = malloc(sizeof(char) * (1 + 1));
    char *src = "T";

    my_strcpy(dest, src);
    strcpy(dest, src);
    cr_assert_str_eq(my_strcpy(dest, src), strcpy(dest, src));
}

Test(my_strcpy, Long)
{
    char *dest = malloc(sizeof(char) * (32 + 1));
    char *src = "Long_test_with_a_long_string_yes";

    my_strcpy(dest, src);
    strcpy(dest, src);
    cr_assert_str_eq(my_strcpy(dest, src), strcpy(dest, src));
}
