// Copyright (C) 2020 Ramsay Carslaw

#include "../include/dict.h"

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
        d = lookup(token, hashtab);
        int length = snprintf(NULL, 0, "%d", d->val);
        char *tmp = malloc(length + 1);
        snprintf(tmp, length + 1, "%d", d->val);
        strcat(result, tmp);
        strcat(result, " ");

        free(tmp);
    }

    free(tofree);
    return result;
}