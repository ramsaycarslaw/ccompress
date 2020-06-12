// Copyright (C) 2020 Ramsay Carslaw

#ifndef CCOMPRESS_UTIL_H
#define CCOMPRESS_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *read_ascii_file(const char *path);

int write_ascii_file(const char *contents, const char *path);

char **split_str(char *str, const char delim);

#endif // CCOMPRESS_UTIL_H