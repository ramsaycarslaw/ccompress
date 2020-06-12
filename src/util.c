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

/* split_str splits a source string into an array of substrings basec on a delimeter. Note: this function will NOT catch repeating delimeters */
char **split_str(char *str, const char delim)
{
    char** result = 0;
    size_t count = 0;
    char* tmp = str;
    char* last_delim = 0;
    char a_delim[2];
    a_delim[0] = delim;
    a_delim[1] = 0;

    // count the number of elements to be removed
    while (*tmp)
    {
        if (delim == *tmp)
        {
            count++;
            last_delim = tmp;
        }
        tmp++;
    }

    // add space for trailing token
    count += last_delim < (str + strlen(str) -1);

    // add space for null terminator
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx = 0;
        char* token = strtok(str, a_delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, a_delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}