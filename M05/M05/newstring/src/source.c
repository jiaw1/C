#include "source.h"
#include <stdio.h>


/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    int i = 0;
    while(s[i] != '?')
    {
        printf("%c", s[i]);
        i++;
    }
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    int i = 0;
    while (s[i] != '?')
    {
        i++;
    }
    return i;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int a = 0, b = 0, i = 0, j = 0;
    b = qstr_length(dst);
    i = b;
    while (src[j] != '?')
    {
        dst[i + j] = src[j];
        j++;
    }
    dst[i+j] = '?';
    a = qstr_length(dst);
    return a;
}
