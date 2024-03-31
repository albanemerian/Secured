/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_compute_power_rec, power_2)
{
    cr_assert_eq(my_compute_power_rec(10, 2), 100);
}

Test(my_compute_power_rec, power_1)
{
    cr_assert_eq(my_compute_power_rec(10, 1), 10);
}

Test(my_compute_power_rec, power_0)
{
    cr_assert_eq(my_compute_power_rec(10, 0), 1);
}

Test(my_compute_power_rec, negative)
{
    cr_assert_eq(my_compute_power_rec(10, -1), 0);
}

Test(my_compute_power_rec, power_3)
{
    cr_assert_eq(my_compute_power_rec(3, 3), 27);
}
