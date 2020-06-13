// Copyright (C) 2020 Ramsay Carslaw

#include "../include/dict.h"

/* dictionary_compression iterates over the source file to find each unique word with which it builds a hashmap.
It then writes the integer values of this hashmap to a file giving the effect of text compression*/
char *dictionary_compression(char *src, dict *d, dict *hashtab[HASHSIZE]) 
{
    char *result = malloc(sizeof(char) * DEST_SIZE);
    char *token, *str, *tofree;
    int i = 0;

    // own src's memory
    tofree = str = strdup(src); 

    while ((token = strsep(&str, " ")))
    {
        d = install(token, i, hashtab);

        i++;
    }

    tofree = str = strdup(src); 

    while ((token = strsep(&str, " ")))
    {
        // get the node for the split string
        d = lookup(token, hashtab);

        // get the length of the string needed to store the number
        int length = snprintf(NULL, 0, "%d", d->val);
        // allocate mem
        char *tmp = malloc(length + 1);
        // itoa
        snprintf(tmp, length + 1, "%d", d->val);
        // append changes
        strcat(result, tmp);
        strcat(result, " ");

        free(tmp);
    }

    free(tofree);
    return result;
}

char *dictionary_decompression(char *src, dict *d, dict *hashtab[HASHSIZE])
{
    char *result = malloc(sizeof(char) * DEST_SIZE);
    char *token, *str, *tofree;
    
    str = tofree = strdup(src);

    while((token = strsep(&str, " ")))
    {
        int x = atoi(token);

        d = lookup_by_val(x, hashtab);

        if (d == NULL)
        {
            continue;
        }

        strcat(result, d->key);
        strcat(result, " ");
    }
    free(tofree);
    return result;
}