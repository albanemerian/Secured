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

Test(my_positive_nbr, Number, .init=redirect_all_stdout)
{
    my_positive_nbr(42);
    cr_assert_stdout_eq_str("42");
}
