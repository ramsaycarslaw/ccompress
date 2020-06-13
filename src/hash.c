// Copyright (C) 2020 Ramsay Carslaw

#include "../include/hash.h"

// main pointer table


/* hash returns a hash val from any given string */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * HASHSIZE;
    }
    return hashval % HASHSIZE;
}

// lookup returns the key/value struct acosiated with a particular key
dict *lookup(char *s, dict *hashtab[HASHSIZE])
{
    dict *d;
    for (d = hashtab[hash(s)]; d != NULL; d = d->next)
    {
        if (strcmp(s, d->key) == 0)
        {
            // found
            return d;
        }
    }
    // not found
    return NULL;
}

dict *lookup_by_val(int val, dict *hashtab[HASHSIZE])
{
    dict *d = hashtab[0];
    int i;

    for (i = 0; i < HASHSIZE; i++)
    {
        
        d = hashtab[i];
        if (d == NULL)
        {
            continue;
        }

        if (d->val == val)
        {
            return d;
        }
    }
    return NULL;
}

dict *install(char *key, int val, dict *hashtab[HASHSIZE])
{
    dict *d;
    unsigned hashval;

    // if key is not in dictionary
    if ((d = lookup(key, hashtab)) == NULL) 
    {   
        d = (dict *) malloc(sizeof(*d));
        if (d == NULL || (d->key = strdup(key)) == NULL)
        {
            // something has gone wrong...
            return NULL;
        }
        // Create the struct
        hashval = hash(key);
        d->next = hashtab[hashval];
        hashtab[hashval] = d;
    } else 
    {
        d->val = -1;
    }
    d->val = val;
    return d;
}

