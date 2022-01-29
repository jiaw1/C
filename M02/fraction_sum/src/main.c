#include <stdio.h>
#include "source.h"

double fracsum(int num1, int num2, int num3, int num4)
{
    double num = (double) num1 / (double) num2;
	double den = (double) num3 / (double) num4;
    return num + den;
}

int main(void)
{
    printf("%.3f %.3f %.3f\n",
	   fracsum(1,2,2,4),
	   fracsum(1,4,1,8),
	   fracsum(4,3,5,6));

    return 0;
}
