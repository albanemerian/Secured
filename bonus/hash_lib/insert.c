/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** insert
*/

#include "../include/hashtable.h"

int table_check(char *key, struct key_val *current, char *value)
{
    int correct = my_strdup(value);

    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            current->str = correct;
            return (current->str);
        }
        current = current->next;
    }
    return 0;
}

int check_table(hashtable_t *ht, char *key, struct key_val *current,
    char *value)
{
    current = ht->table[current->index];
    if (table_check(key, current, value) != 0)
        return 0;
    return 1;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    struct key_val *current;

    if (ht == NULL || ht->size < 1 || key == NULL || value == NULL ||
        key[0] == '\0' || value[0] == '\0')
        return 84;
    current = malloc(sizeof(struct key_val));
    if (current == NULL)
        return 84;
    current->key = my_strdup(key);
    current->value = ht->hash(key, ht->size);
    current->index = ht->hash(key, ht->size) % (ht->size);
    current->str = my_strdup(value);
    current->value = ht->hash(key, ht->size);
    current->next = ht->table[current->index];
    if (check_table(ht, key, current, value) == 0)
        return 0;
    else
        ht->table[current->index] = current;
    return 0;
}
