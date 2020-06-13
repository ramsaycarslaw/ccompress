// Copyright (C) 2020 Ramsay Carslaw

#ifndef CCOMPRESS_DICT_H
#define CCOMPRESS_DICT_H

/*** Includes ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** Defines ***/

// prime for hashing algorithm
#define HASHSIZE 101

/*** Structs ***/

// new type like go's map or python's dictionary
typedef struct dict {
    struct dict *next;
    char *key;
    int val;
} dict;

/*** Functions ***/

unsigned hash(char *s);

dict *lookup(char *s, dict *hashtab[HASHSIZE]);

dict *lookup_by_val(int val, dict *hashtab[HASHSIZE]);

dict *install(char *key, int val, dict *hashtab[HASHSIZE]);

#endif // CCOMPRESS_DICT_H