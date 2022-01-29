#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z)
{
    double potsum = x*x + y*y + z*z;
    double length = sqrt(potsum);
    return length;
}

