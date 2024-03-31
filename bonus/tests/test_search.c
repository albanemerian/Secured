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

Test(ht_search, Normal, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "Kratos", "oui");
    cr_assert_str_eq(ht_search(ht, "Kratos"), "oui");
}

Test(ht_search, Inexistant, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "Kratos", "oui");
    cr_assert_null(ht_search(ht, "Kartos"));
}

Test(ht_search, Key_null, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "Kratos", "oui");
    cr_assert_null(ht_search(ht, NULL));
}

Test(ht_search, Negative, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "f TYeir", "test");
    cr_assert_str_eq(ht_search(ht, "f TYeir"), "test");
}

Test(ht_search, Hashtable_null, .init=redirect_all_stdout)
{
    hashtable_t *ht = NULL;

    cr_assert_null(ht_search(ht, "Kratos"));
}

Test(ht_search, hashtableSize_null, .init=redirect_all_stdout)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    cr_assert_null(ht_search(ht, "Kratos"));
}
