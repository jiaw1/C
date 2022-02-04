/*  The code below does not compile and produce the required output.
 *  Try first to understand why it does not compile. What does the compiler error mean?
 *  After that, correct the code so that it compiles and produces the correct
 *  value of the variable a after the mathematical operations.
 */

#include <stdio.h>

int main(void)
{
    int a = 1;
    a = a + 1;
    
    int b = 6;
    b = b + 1;
    
    a = a + b;
    printf("a: %d", a);
    return 0;
}
#include "source.h"

#include <math.h>
#include <stdio.h>

void simple_math(void)
{

    int number1, space1, operator, space2, number2;
    int ret;
    ret = scanf("%f" "%d" "%d" "%d" "%f", &number1, &space1, &operator, &space2, &number2);
    
    if (ret >= 5){

        if (operator == "+"){
            printf(number1+number2);
        }else if (operator == "-"){
            printf(number1-number2);
        }else if (operator == "*"){
            printf(number1*number2);
        }else if (operator == "/"){
            printf(number1/number2);
        }else{
            printf("ERR\n");
        }
    }
    else{
        printf("ERR\n");
    }

    return 0;
}
