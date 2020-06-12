// Copyright (C) 2020 Ramsay Carslaw

#include "../include/util.h"

/* read_ascii_file takes a path to a file as an argument and returns its contents as a char * */
char *read_ascii_file(const char *path) 
{
    // create a file pointer 
    FILE* file = fopen(path, "r");
    if (!file)
    {
        printf("ERROR: could not open file %s...\n", path);
        return NULL;
    }

    // get the file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // read file
    char* buf = malloc(sizeof(char) * (size + 1));
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    return buf;
}

/* write_ascii_file takes contents of a file and the path to be writen to and writes to the given path */
int write_ascii_file(const char *contents, const char *path)
{
    // create file pointer
    FILE* file = fopen(path, "w");

    if (!file)
    {
        printf("ERROR: could not open %s...\n", path);
        return -1;
    }

    fprintf(file, "%s", contents);
    fclose(file);

    return 0;
}