#include "../include/dict.h"

char *dictionary_compression(char *src, dict *d, dict *hashtab[HASHSIZE]) 
{
    char **tokens;
    char* result = malloc(sizeof(char) * DEST_SIZE);

    tokens = split_str(src, ' '); // need to fix split string

    if (!tokens)
    {
        printf("ERROR: Could not split source string...\n");
        return NULL;
    }
    int i;
    int j;

    for (i = 0; *(tokens + i); i++)
    {
        d = install(*(tokens + i), i, hashtab);
    }
    
    for (j = 0; *(tokens + j); j++)
    {
        d = lookup(*(tokens + j), hashtab);
        int length = snprintf(NULL, 0, "%d", d->val);
        char *tmp = malloc(length + 1);
        snprintf(tmp, length, "%d", d->val);

        strcat(result, tmp);
        strcat(result, " ");

        free(tmp);
    }
    return result;
}