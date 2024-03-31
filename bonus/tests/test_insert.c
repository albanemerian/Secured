/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

Test(ht_insert, No_value)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    cr_assert_eq(ht_insert(ht, "", "value"), 84);
}

Test(ht_insert, No_key)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    cr_assert_eq(ht_insert(ht, "key", ""), 84);
}

Test(new_hashtable, Negative_ht)
{
    cr_assert_null(new_hashtable(&hash, -1));
}
