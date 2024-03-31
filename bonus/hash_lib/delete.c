/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** delete
*/

#include "../include/hashtable.h"

void delet_list(struct key_val *current)
{
    if (current == NULL)
        return;
    if (current->next != NULL)
        delet_list(current->next);
    free(current->str);
    free(current);
}

void delete_hashtable(hashtable_t *ht)
{
    struct key_val *current;

    if (ht == NULL) {
        write(2, "Empty table cannot delte\n", 26);
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        current = ht->table[i];
        delet_list(current);
    }
    free(ht->table);
    free(ht);
    ht->size = 0;
}
