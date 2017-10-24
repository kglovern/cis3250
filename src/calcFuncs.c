/**
 * @file    calcFuncs.c
 * @author  Kevin Glover-Netherton, Maddie Gabriel
 * @date    2017-10-20
 *
 * @desc    This file was created during the refactoring of 'cis3250-legacy-calculator.c' to
 *          remove the code from the original .c file. Now, 'calcFuncs.h' will be a
 *          proper header file and will declare the functions that are
 *          implemented here.
 *
 *          The functions in this file implement the functions declared in
 *          'calcFuncs.h'.
**/

#include "calcFuncs.h";

void printMenuHeader ( char *header ) {
    int messageLen = 0;
    int i = 0;

    messageLen = strlen( header ) + 2;

    printf( "\n" );
    for ( i = 0; i < messageLen; i++ ) {
        printf( "=" );
    }
    printf( "\n %s \n", header );
    for ( i = 0; i < messageLen; i++ ) {
        printf( "=" );
    }
    printf( "\n" );
}


void getUserInput ( float *firstOp, float *secondOp ) {
    *firstOp = input( "Enter value of 1st operand: " );
    *secondOp = input( "Enter value of 2nd operand: " );
}


float runTwoOpCalc ( char symbol, float (*calcFP) (float, float) ) {
    float firstOp = 0;
    float secondOp = 0;
    float result = 0;

    getUserInput( &firstOp, &secondOp );
    result = calcFP( firstOp, secondOp );

    printf( "\nResult of %.2f %c %.2f = %.2f", firstOp, symbol, secondOp, result );
    return result;
}


void runRegCalc () {
    int choice = 0;

    do {
        printMenuHeader( "Regular Calculator Menu" );
        printf( "1.PLUS\n" );
        printf( "2.MINUS\n" );
        printf( "3.MULTIPLY\n" );
        printf( "4.DIVIDE\n" );
        printf( "0.BACK\n" );

        choice = input( "Select Menu: " );
        
        system( "clear" );

        if ( choice == 1 ) {                // Addition
            runTwoOpCalc( '+', plus );
        } else if ( choice == 2 ) {         // Subtraction
            runTwoOpCalc( '-', minus );
        } else if ( choice == 3 ) {         // Multiplication
            runTwoOpCalc( '*', mult );
        } else if ( choice == 4 ) {         // Division
            runTwoOpCalc( '/', divind );
        }  else {
            continue;
        }
    } while ( choice != 0 );
}


void matrixMenu () {
    int choice = 0;

    printMenuHeader( "Matrix Operations" );
    printf( "1.Sum of Matrices\n" );
    printf( "2.Transpose\n" );
    printf( "3.Product of Matrices\n" );
    choice = input( "Enter an operation command: " );

    switch ( choice ) {
        case 1: 
            matrix_sum();
            break;
        case 2: 
            matrix_transpose();
            break;
        case 3: 
            matrix_product();
            break;
        default:
            break;
    }

}


void conversionMenu () {
    int choice = 0;

    printMenuHeader( "Conversion Menu" );
    printf( "1.Temperature(1)\n" );
    printf( "2.Time\n" );
    choice = input( "Please choose an operation number:" );

    switch ( choice ) {
        case 1: 
            temp();
            break;
        case 2: 
            time();
            break;
        default:
            break;
    }

}


void runSciCalc () {
    float choice = 0;
    float firstOp = 0;
    float secondOp = 0;
    float result = 0;

    do {
        printMenuHeader( "Scientific Calculator Menu" );
        printf( "1.Power function (x^y)\n" );
        printf( "2.Factorial Series (x!)\n" );
        printf( "3.Fibonacci Series \n" );
        printf( "4.Sine (Sin x)\n" );
        printf( "5.Cosine (cos x)\n" );
        printf( "6.Tangent (Tan x)\n" );
        printf( "7.Cosec (cosec x)\n" );
        printf( "8.Sec (sec x)\n" );
        printf( "9.Cot (cot x)\n" );
        printf( "10.Matrix functions\n" );
        printf( "11.Conversion functions\n" );
        printf( "0.Back\n" );
        choice = input("Select Menu: ");
        system( "clear" );

        if ( choice == 1 ) {
            firstOp = input( "Enter base(x): " );
            secondOp = input( "Enter power(y): " );
            result = powerfn( firstOp, secondOp );
            print( "\nResult of", "^" , firstOp, secondOp, result);
        } else if ( choice == 2 ) {
            firstOp = input( "Enter numbers of term: " );
            result = fact( firstOp );
            spprint( "\nFactorial of", "!" , firstOp, result );
        } else if ( choice == 3 ) {
            firstOp = input( "Enter numbers of term: " );
            result = fib(firstOp);
            spprint( "\nFibonacci of", " ", firstOp, result );
        } else if ( choice == 4 ) {
            firstOp = input( "Enter your value: " );
            result = sine( firstOp );
            spprintf( "\nSine of", " ", firstOp, result );
        } else if ( choice == 5 ) {
            firstOp = input( "Enter your value: " );
            result = cosine( firstOp );
            spprintf( "\nCosine of", " ", firstOp, result );
        } else if ( choice == 6 ) {
            firstOp = input( "Enter your value: ");
            secondOp = sine( firstOp );
            result = cosine( firstOp );
            result = secondOp / result;
            spprintf( "\nTangent of", " ", firstOp, result );
        } else if ( choice == 7 ) {
            firstOp = input( "Enter your value: " );
            result = sine( firstOp );
            spprintf( "Cosec of", " ", firstOp, (1/result) );
        } else if ( choice == 8 ) {
            firstOp = input( "Enter your value: " );
            result = cosine( firstOp );
            spprintf( "\nSec of", " ", firstOp, (1/result) );
        } else if ( choice == 9 ) {
            firstOp = input( "Enter your value: " );
            secondOp = sine( firstOp );
            result = cosine( firstOp );
            result = secondOp / result;
            spprintf( "\nCot of", " ", firstOp, (1/result) );
        } else if ( choice == 10 ) {
            matrixMenu();
        } else if ( choice == 11 ) {
            conversionMenu();
        } else {
            continue;
        }
    } while ( choice != 0 );
}
