

/****** Kevin's Section *******/
#ifndef CALC_FUNCS_H
#define CALC_FUNCS_H

/**
 * Prints a message surrounded by '=' as a banner header
 * @param header The message to be printed
 */
void printMenuHeader ( char *header );


/**
 * Function to get user input and updates argument pointers with the value
 * @param firstOp The first operand to get input for
 * @param secondOp The second operand to get input for
 */
void getUserInput ( float *firstOp, float *secondOp );


/**
 * Function to get two operands from the user, perform a specified operation, and return the result
 * @param symbol The symbol of the operation being performed
 * @param calcFP Function pointer to the operation function being performed
 * @return Float value corresponding to the result
 */
float runTwoOpCalc ( char symbol, float ( *calcFP ) ( float, float ) );

/**
 * Runs the regular calculator menu and branches based on user input
 */
void runRegCalc ();


/*
 * Sub menu for matrix operations
 */
void matrixMenu ();

/**
 * Sub menu for conversion operations
 */
void conversionMenu ();


/**
 * Runs the Scientific calculator menu and branches based on user input
 */
void runSciCalc ();

#endif
/******* End of Kevin's Section *******/
