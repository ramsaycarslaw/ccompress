// Copyright (C) 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"
#include "../include/hash.h"
#include "../include/dict.h"
#include "../include/licence.h"
#include "../include/user.h"

static dict *hashtab[HASHSIZE]; 

int main(int argc, char **argv) 
{
    if (argc < 3)
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

        //printf("%s\n", compressed);

        int ok = write_ascii_file(compressed, "test/file.txt.cmp");

        char *decompressed = read_ascii_file("test/file.txt.cmp");

        char *result = dictionary_decompression(decompressed, d, hashtab);

        printf("%s\n", result);

        // control of source mem handed to main by read_ascii_file
        free(result);
        free(compressed);
        free(source);

    } else if (strcmp(argv[1], "licence") == 0)
    {
        licence(argv[2]);
        
    } else if (strcmp(argv[1], "decompress") == 0)
    {
        dict *d;

        d = lookup_by_val(202, hashtab);
        //char *decompressed = read_ascii_file(argv[2]);

        //char *result = dictionary_decompression(decompressed, d, hashtab);

        //printf("%s\n", result);
        //free(result);
    }

    return 0;
}