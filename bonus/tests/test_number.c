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

Test(my_unsigned_nbr, Unit, .init=redirect_all_stdout)
{
    my_unsigned_nbr(5);
    cr_assert_stdout_eq_str("5");
}

Test(my_unsigned_nbr, Hundred, .init=redirect_all_stdout)
{
    my_unsigned_nbr(128);
    cr_assert_stdout_eq_str("128");
}

Test(my_put_nbr, Negative, .init=redirect_all_stdout)
{
    my_put_nbr(-450);
    cr_assert_stdout_eq_str("-450");
}

Test(my_put_nbr, Return, .init=redirect_all_stdout)
{
    cr_assert_eq(my_put_nbr(658), 0);
}
