/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** my_strcmp
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, Basic)
{
    cr_assert(my_strcmp("hello", "hello") == 0);
}

Test(my_strcmp, different_lengths)
{
    cr_assert(my_strcmp("hello", "world") < 0);
    cr_assert(my_strcmp("world", "hello") > 0);
}

Test(my_strcmp, different_characters)
{
    cr_assert(my_strcmp("abc", "abd") < 0);
    cr_assert(my_strcmp("abd", "abc") > 0);
}

Test(my_strcmp, string_prefix)
{
    cr_assert(my_strcmp("prefix", "prefixes") < 0);
    cr_assert(my_strcmp("prefixes", "prefix") > 0);
}

Test(my_strcmp, empty_strings)
{
    cr_assert(my_strcmp("", "") == 0);
}
