#include "shared.h"
#include <stdio.h>
#include <string.h>

long shared_lib_function(char* msg)
{
    printf("Hi! I'm a dynamic lib that receives '%s', and return '%ld'\n",msg, strlen(msg));
    return strlen(msg);
}
