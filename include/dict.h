#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "util.h"

#define DEST_SIZE 1000000

char *dictionary_compression(char *src, dict *d, dict *hashtab[HASHSIZE]);