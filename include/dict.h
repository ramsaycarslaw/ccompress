// Copyright (C) 2020 Ramsay Carslaw

#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "util.h"

#define DEST_SIZE 1000000

char *dictionary_compression(ht_t *hashtable, const char *src);
