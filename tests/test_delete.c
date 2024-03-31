/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ht_delete, Not_exist, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "test", "un test!");
    ht_delete(ht, "tests");
    cr_assert_stderr_eq_str("Key not found\n");
}

Test(ht_delete, ErrorReturn, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "test", "un test!");
    cr_assert_eq(ht_delete(ht, "tests"), 84);
}

Test(ht_delete, Exist, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "test", "un test!");
    ht_insert(ht, "frite", "un autre test!");
    ht_insert(ht, "oui", "encore un!");
    cr_assert_eq(ht_delete(ht, "oui"), 0);
}

Test(ht_delete, Exist2, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "test", "un test!");
    ht_insert(ht, "frite", "un autre test!");
    ht_insert(ht, "oui", "encore un!");
    cr_assert_eq(ht_delete(ht, "test"), 0);
}
