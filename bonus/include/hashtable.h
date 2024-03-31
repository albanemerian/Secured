/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"

#ifndef HASHTABLE_H
    #define HASHTABLE_H

struct key_val {
    char *str;
    int value;
    char *key;
    struct key_s *next;
    int index;
};

typedef struct hashtable_s {
    struct key_val **table;
    int (*hash)(char *, int);
    int size;
    struct hashtable_s *next;
} hashtable_t;

typedef struct scenes_s {
    bool no_ht;
    bool ht_size;
    bool ht;
    bool insert_key;
    bool insert_val;
    bool insert;
    bool search;
    bool delkey;
    bool deletion;
    int elem;
} scenes_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
