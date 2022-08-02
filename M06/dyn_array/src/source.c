#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "source.h"

/**
 * \brief Creates a dynamically allocated array and reads the specified number of
 *        integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */
int *create_dyn_array(unsigned int n)
{
    int *arr;
    arr = malloc(n * sizeof(unsigned int));
    for (unsigned int i = 0; i < n; i++) 
    {
        scanf("%u", &arr[i]);
    }
    return arr;
}


/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    int *arr2 = realloc(arr, (num + 1) * sizeof(unsigned int));
    arr2[num] = newval;
    return arr2;
}
