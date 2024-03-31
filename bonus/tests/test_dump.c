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

Test(ht_dump, Empty, .init=redirect_all_stdout)
{
    hashtable_t *ht = NULL;

    ht_dump(ht);
    cr_assert_stderr_eq_str("Empty table cannot dump\n");
}

Test(ht_dump, No_key, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n");
}

Test(ht_dump, Key, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "plz", "test1");
    ht_insert(ht, "pls", "test2");
    ht_dump(ht);
}
