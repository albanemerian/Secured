/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_getnbr, Number)
{
    cr_assert_eq(my_getnbr("42"), 42);
}

Test(my_getnbr, Zero)
{
    cr_assert_eq(my_getnbr("0"), 0);
}

Test(my_getnbr, Negative)
{
    cr_assert_eq(my_getnbr("-84"), -84);
}

Test(my_getnbr, BiggestNegative)
{
    cr_assert_eq(my_getnbr("-2147483649"), 0);
}

Test(my_getnbr, BiggestPositive)
{
    cr_assert_eq(my_getnbr("2147483648"), 0);
}

Test(my_getnbr, NoNumber)
{
    cr_assert_eq(my_getnbr("Wilfried"), 0);
}

Test(my_getnbr, EmptyString)
{
    cr_assert_eq(my_getnbr(""), 0);
}

Test(my_getnbr, InsaneNumber)
{
    cr_assert_eq(my_getnbr("154875489558"), 0);
}

Test(my_getnbr, InsaneSign)
{
    cr_assert_eq(my_getnbr("+--+45"), 45);
}
