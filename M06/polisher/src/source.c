#include "source.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{
    int len = strlen(input);
    char *input2 = malloc(strlen(input) * sizeof(char) + 1);
    int i = 0;
    for (int j = 0; j < len; j++) 
    {
        if ((input[j] == '/') && (input[j + 1] == '*'))
        {
            while ((input[j] != '*') || (input[j + 1] != '/'))
            {
                j++;
            }
            j++;
        }
        else if ((input[j] == '/') && (input[j + 1] == '/'))
        {
            while (input[j] != '\n'){
                j++;
            }
        }
        else
        {
            input2[i] = input[j];
            i++;
        }
    }
    input2[i] = 0;
    free(input);
    return input2;  
}
