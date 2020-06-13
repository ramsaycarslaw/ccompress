// Copyright (C) 2020 Ramsay Carslaw

#include "../include/user.h"


void licence(char *passed)
{
    if (strcmp(passed, "show") == 0)
    {
        printf("%s\n", LICENCE);
    } else {
        printf("This program is licenced under GPLv3\nfor more info type 'ccompress licence show'\n");
    }
}

