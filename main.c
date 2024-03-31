/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include "include/hashtable.h"
#include "include/my.h"

hashtable_t *test_2(hashtable_t *ht)
{
    ht_insert(ht, NULL, "defe");
    mini_printf("both empty \n");
    ht_insert(ht, "", "");
    mini_printf("both null\n");
    ht_insert(ht, NULL, NULL);
    ht_search(ht, NULL);
    ht_search(ht, "");
    ht_delete(ht, "02");
    ht_delete(ht, "03");
    ht_delete(ht, "03");
    printf("\nLooking for \"%s\":\"%s\"\n", " 05",
        ht_search(ht, "05"));
    printf("\nLooking for \"%s\":\"%s\"\n", " 02",
        ht_search(ht, "02"));
    ht_dump(ht);
    mini_printf("\n deleting inexistant node\n");
    ht_delete(ht, "Fun");
    delete_hashtable(ht);
    ht_dump(ht);
    return (ht);
}

hashtable_t *test(hashtable_t *ht)
{
    ht_dump(ht);
    ht_insert(ht, "05", "bonjour");
    ht_insert(ht, "04", "fun");
    mini_printf("\nFilled :\n");
    ht_dump(ht);
    mini_printf("\n");
    mini_printf("Looking for \"%s \n\n", "Kra");
    ht_search(ht, "Kra");
    ht_search(ht, "edefe");
    ht_delete(ht, NULL);
    mini_printf("Visions && kratos was deleted :)\n");
    ht_delete(ht, "01");
    ht_dump(ht);
    mini_printf("\none empty string\n");
    ht_insert(ht, "fd", "");
    mini_printf("one null arg\n");
    ht_insert(ht, "ezf", NULL);
    mini_printf("key null\n");
    test_2(ht);
    return (ht);
}

int main(int argc, char **argv)
{
    hashtable_t *ht = NULL;

    if (argc > 1)
        return 84;
    delete_hashtable(ht);
    ht_dump(ht);
    ht_insert(ht, NULL, NULL);
    ht_search(ht, NULL);
    ht_delete(ht, NULL);
    hash("ferfe", -1);
    ht = new_hashtable(&hash, 5);
    mini_printf("\nEmpty :\n");
    ht_dump(ht);
    ht_insert(ht, "01", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "02", "./Trash/Hollidays_Pics/.secret/kratos.ai");
    ht_insert(ht, "03", "+33 63145612371");
    ht_insert(ht, "04", "theh enkdjer");
    ht_insert(ht, "05", "dkjf fehtrkh");
    test(ht);
    return 0;
}
