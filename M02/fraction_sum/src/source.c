# include <stdio.h>
# include "source.h"

double fracsum(int num1, int num2, int num3, int num4)
{
    double num = (double) num1 / (double) num2;
	double den = (double) num3 / (double) num4;
    return num + den;
}
