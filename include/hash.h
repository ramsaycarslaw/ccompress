// Copyright (C) 2020 Ramsay Carslaw

#ifndef CCOMPRESS_HASH_H
#define CCOMPRESS_HASH_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20000

typedef struct entry_t {
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct {
    entry_t **entries;
} ht_t;

unsigned int hash(const char *key);

entry_t *ht_pair(const char *key, const char *value);

ht_t *ht_create(void);

void ht_set(ht_t *hashtable, const char *key, const char *value);

char *ht_get(ht_t *hashtable, const char *key);

char *ht_get_key(ht_t *hashtable, const char *value);

void ht_del(ht_t *hashtable, const char *key);

void ht_dump(ht_t *hashtable);

#endif // CCOMPRESS_HASH_H