/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** new_hash
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (ht == NULL)
        return NULL;
    if (len < 1) {
        write(2, "Incorrect length\n", 17);
        free(ht);
        return NULL;
    }
    ht->table = malloc(sizeof(struct key_val *) *len);
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        ht->table[i] = NULL;
    ht->size = len;
    ht->hash = hash;
    return ht;
}
