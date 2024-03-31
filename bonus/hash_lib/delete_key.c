/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** delete_key
*/

#include "../include/hashtable.h"

static void oui(struct key_val **prev, struct key_val *current,
    struct key_val **head)
{
    if (*prev != NULL) {
        (*prev)->next = current->next;
    } else {
        *head = current->next;
    }
}

static int delete_int(struct key_val **head, int ind)
{
    struct key_val *current = *head;
    struct key_val *prev = NULL;

    while (current != NULL) {
        if (current->value == ind) {
            oui(&prev, current, head);
            free(current->str);
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 84;
}

static int last_del(hashtable_t *ht, int ind)
{
    int i = ind % ht->size;
    struct key_val *head = ht->table[i];

    if (delete_int(&head, ind) == 0) {
        ht->table[i] = head;
        return 0;
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int ind;

    if (ht != NULL && key != NULL && key[0] != '\0') {
        ind = ht->hash(key, ht->size);
        if (last_del(ht, ind) == 0)
            return 0;
    }
    write(2, "Key not found\n", 14);
    return 84;
}
