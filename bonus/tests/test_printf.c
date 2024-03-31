/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mini_printf, Char, .init=redirect_all_stdout)
{
    mini_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(mini_printf, Percentage, .init=redirect_all_stdout)
{
    mini_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(mini_printf, Str, .init=redirect_all_stdout)
{
    mini_printf("%s", "tests");
    cr_assert_stdout_eq_str("tests");
}

Test(mini_printf, Nbr, .init=redirect_all_stdout)
{
    mini_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}
