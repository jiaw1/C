#include "source.h"

#include <stdlib.h>
#include <string.h>

char *mystrcat(char *dest, const char *src)
{
    dest = realloc(dest, 50);
    char *origdest = dest;
    
    while (*dest)
    {
        dest++;
    }

    while (*src)
    {
        *dest++ = *src++; // Copy the source
    }
    *dest = 0;

    return origdest;
}
