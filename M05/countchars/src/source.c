#include <stdio.h>

/**
 * \brief Counts the number of occurrences of characters in an array
 *
 * \param array A zero (0) terminated string that is composed some number of characters
 * \param counts An int array of 256 elements that contains number of character occurrences.
 */

void countchars(const char *array, unsigned int *counts)
{
    int boolean = 0;
    int i = 0;
    while(boolean == 0)
    {
        if (array[i] != 0)
        {
            counts[(int)array[i]]++;
            i++;
        }
        else boolean = 1;
    }
}