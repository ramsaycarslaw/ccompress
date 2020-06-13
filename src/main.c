// Copyright (C) 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"
#include "../include/hash.h"
#include "../include/dict.h"
#include "../include/licence.h"
#include "../include/user.h"

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

        ht_t *hashtable = ht_create();
        char * compressed = dictionary_compression(hashtable, source);

        printf("%s\n", compressed);

        int ok = write_ascii_file(compressed, "test/file.txt.cmp");

        free(compressed);
        free(source);

    } else if (strcmp(argv[1], "licence") == 0)
    {
        licence(argv[2]);
        
    } 
    return 0;
}