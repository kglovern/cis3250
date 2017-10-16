#include <stdio.h>

/**Function to calculate the result of a number raised to a power
*@param x - the base of the exponential expression
*@param n - the exponent (or power) of the exponential expression
*@return the result of the exponential calculation
**/
double powerfn ( double base, int exponent ) {

    int i = 0;
    double result = 1;

    for ( i = 1; i <= exponent; i++ ) {
        result *= base;
    }

    return result;
}

