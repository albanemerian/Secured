/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** dump
*/

#include "../include/hashtable.h"

void dump(struct key_val *current)
{
    while (current != NULL) {
        mini_printf("> %d - %s\n", current->value, current->str);
        current = current->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    struct key_val *current;
    int i = 0;

    if (ht == NULL || ht->size < 1) {
        write(2, "Empty table cannot dump\n", 24);
        return;
    }
    while (i < ht->size) {
        current = ht->table[i];
        if (current == NULL) {
            mini_printf("[%i]:\n", i);
        } else {
            mini_printf("[%i]:\n", i);
            dump(current);
        }
        i++;
    }
}
