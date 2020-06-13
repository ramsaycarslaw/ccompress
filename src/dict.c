// Copyright (C) 2020 Ramsay Carslaw

#include "../include/dict.h"

/* dictionary_compression iterates over the source file to find each unique word with which it builds a hashmap.
It then writes the integer values of this hashmap to a file giving the effect of text compression*/
char *dictionary_compression(ht_t *hashtable, const char *src) 
{
    char *result = malloc(sizeof(char) * DEST_SIZE);
    char *token, *str, *tofree;
    int i = 0;

    // own src's memory
    tofree = str = strdup(src); 

    while ((token = strsep(&str, " ")))
    {
        char snum[20];
        sprintf(snum, "%d", i);
        ht_set(hashtable, token, snum);

        i++;
    }

    tofree = str = strdup(src); 

    while ((token = strsep(&str, " ")))
    {
        char *tmp = ht_get(hashtable, token);
        strcat(result, tmp);
        strcat(result, " ");
    }

    free(tofree);
    return result;
}

