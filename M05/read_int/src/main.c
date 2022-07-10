#include <stdio.h>

int read_int(int *number)
{
    int ret;
    int fail = -1;
    if (number == NULL) { // Check the given pointer
        return fail; // If the pointer is NULL, exit the function
    }
    ret = scanf("%d", number);
    if (ret != 1) { // Check whether reading succeeded
        return fail;
    }
    return *number;
}

int main(void)
{
    int a;
    int *ptr_a = &a;
    int ret = -1000;
    if (read_int(ptr_a) != 1){
        printf("reading succeeded: %d\n", a);
    }
    else
    {
        printf("not a valid number\n");
    }
    ret = read_int(&a);
    printf("r: %d\n", ret);
    
    return 0;
}

