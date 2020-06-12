// Copyright (C) 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"
#include "../include/hash.h"
#include "../include/dict.h"

static dict *hashtab[HASHSIZE]; 

int main(int argc, char **argv) 
{
    if (argc <3)
    {
        printf("ERROR: too many arguments...\n");
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) 
    {
        char* source = read_ascii_file(argv[2]);
        if (source == NULL) 
        {
            return 1;
        }

        dict *d;
        char * compressed = dictionary_compression(source, d, hashtab);

        printf("%s\n", compressed);

        // control of source mem handed to main by read_ascii_file
        free(compressed);
        free(source);
    }

    return 0;
}