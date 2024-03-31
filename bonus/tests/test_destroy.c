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

Test(delete_hashtable, Empty, .init=redirect_all_stdout)
{
    hashtable_t *ht = NULL;

    delete_hashtable(ht);
}

Test(delete_hashtable, No_key, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    delete_hashtable(ht);
}

Test(delete_hashtable, Key, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "plz", "test1");
    ht_insert(ht, "pls", "test2");
    delete_hashtable(ht);
}
