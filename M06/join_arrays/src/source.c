#include <stdio.h>
#include <stdlib.h>
#include "source.h"

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array
 * \param a2 The array 1 composed of n1 elements
 * \param n3 The number of elements in array
 * \param a3 The array 1 composed of n1 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1,
                 const int *a1,
                 unsigned int n2,
                 const int *a2,
                 unsigned int n3,
                 const int *a3)
{
    int n = n1 + n2 + n3;
    int *A;
    A = (int*)malloc(n * sizeof(int));
    int x = 0;

    for (unsigned int i = 0; i < n1; i++)
    {
        A[x] = a1[i];
        x++;
    }

    for (unsigned int j = 0; j < n2; j++)
    {
        A[x] = a2[j];
        x++;
    }

    for (unsigned int z = 0; z < n3; z++)
    {
        A[x] = a3[z];
        x++;
    }

    return A;
}
