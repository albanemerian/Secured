/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** search
*/

#include "../include/hashtable.h"

int search_int(hashtable_t *ht, struct key_val *current, int i, int value)
{
    while (current != NULL) {
        if (current->value == value)
            return (current->str);
        current = current->next;
        i++;
    }
    return 0;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int value;
    struct key_val *current;

    if (ht == NULL || ht->size < 1) {
        write(2, "Invalid length\n", 15);
        return (NULL);
    }
    if (key == NULL || key[0] == '\0')
        return (NULL);
    value = ht->hash(key, ht->size);
    for (int i = 0; i < ht->size; i++) {
        current = ht->table[i];
        if (search_int(ht, current, i, value) != 0)
            return (current->str);
    }
    return (NULL);
}
