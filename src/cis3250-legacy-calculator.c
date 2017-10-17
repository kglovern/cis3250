#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832795
#include "factorial.h"
#include "matrices.h"
#include "powerfunction.h"
#include "conversions.h"
#include<string.h>

FILE*help;


float input(char*inname)
{
    float key;
    char temp[9999];
    
    do{
    printf("%s",inname);
     if(!scanf("%f",&key)){
        scanf("%s",&temp);//recieve temp
            printf("Please try again!\n");
    }
    else{
        return key;
    }
    }while(1);   
}

float inputAry(char*inname,int num)
{
    float key;
    char temp[9999];

    do{
    printf("%s[%d]: ",inname,num+1);
     if(!scanf("%f",&key)){
        scanf("%s",&temp);
            printf("Please try again!\n");
    }
    else{
        return key;
    }
    }while(1);   
}

float plus(float adder,float addin)
{
    float result;
    result=adder+addin;
    return result;
}

float minus(float miner,float minin)
{
    float result;
    result=miner-minin;
    return result;
}

float mult(float multer,float multin)
{
    float result;
    result=multer*multin;
    return result;
}

float divind(float divider,float dividin)
{
    float result;
    result=divider/dividin;
    return result;
}

int factorial(int term)
{

    if(term==0){
        return 1;
    }

    return term*factorial(term-1);
}

int fib(int term)
{
    if(term==1){
        return 0;
    }
    if(term==2){
        return 1;
    }
    return fib(term-1)+fib(term-2);
}

float power(float base,int pow)
{
    int i;
    float mem=1;
    for(i=0;i<pow;i++){
        mem*=base;
    }
    return mem;
}

float sine(float radius)
{
    float val,sin;
        val=radius*(PI/180);
        sin=val-(power(val,3)/factorial(3))+(power(val,5)/factorial(5))-(power(val,7)/factorial(7));
    return sin;
}

float cosine(float radius)
{
    float val,cos;
        val=radius*(PI/180);
        cos=1-(power(val,2)/factorial(2))+(power(val,4)/factorial(4))-(power(val,6)/factorial(6));
    return cos;
}

int spprint(char*screen,char*sym,int ini,int res)
{
    printf("%s %d%s = %d\n",screen,ini,sym,res);
    
return 0;
}

float spprintf(char*screen,char*sym,float ini,float res)
{
    printf("%s %.4f%s = %.4f\n",screen,ini,sym,res);

return 0;
}

float print(char*screen,char*sym,float ini,float upt,float res)
{
    printf("%s %.4f %s %.4f = %.4f\n",screen,ini,sym,upt,res);

return 0;
}
float Aryprint(char*screen,float ans)
{
    printf("%s : %.4f\n",screen,ans);

return 0;
}

/*Kevin's Section */
/**
 * Prints a message surrounded by '=' as a banner header
 * @param header The message to be printed
 */
void printMenuHeader ( char *header ) {
    int messageLen = 0;
    int i = 0;

    messageLen = strlen ( header ) + 2;

    printf ("\n");
    for ( i = 0; i < messageLen; i ++ ) {
        printf ("=");
    }
    printf ("\n %s \n", header );
    for ( i = 0; i < messageLen; i ++ ) {
        printf ("=");
    }
    printf ("\n");
}


/**
 * Function to get user input and updates argument pointers with the value
 * @param firstOp The first operand to get input for
 * @param secondOp The second operand to get input for
 */
void getUserInput ( float *firstOp, float *secondOp ) {
    *firstOp = input ("Enter value of 1st operand: ");
    *secondOp = input ("Enter value of 2nd operand: ");
}


/**
 * Function to get two operands from the user, perform a specified operation, and return the result
 * @param symbol The symbol of the operation being performed
 * @param calcFP Function pointer to the operation function being performed
 * @return Float value corresponding to the result
 */
float runTwoOpCalc ( char symbol, float (*calcFP) (float, float) ) {
    float firstOp = 0;
    float secondOp = 0;
    float result = 0;

    getUserInput ( &firstOp, &secondOp);
    result = calcFP (firstOp, secondOp);

    printf ("\nResult of %.2f %c %.2f = %.2f", firstOp, symbol, secondOp, result);
    return result;
}


/**
 * Runs the regular calculator menu and branches based on user input
 */
void runRegCalc () {
    int choice = 0;

    do {
        printMenuHeader ("Regular Calculator Menu");
        printf ("1.PLUS\n");
        printf ("2.MINUS\n");
        printf ("3.MULTIPLY\n");
        printf ("4.DIVIDE\n");
        printf ("0.BACK\n");

        choice = input ("Select Menu: ");
        
        system ("clear");

        if ( choice == 1 ) {                // Addition
            runTwoOpCalc ( '+', plus );
        } else if ( choice == 2 ) {         // Subtraction
            runTwoOpCalc ( '-', minus );
        } else if ( choice == 3 ) {         // Multiplication
            runTwoOpCalc ( '*', mult );
        } else if ( choice == 4 ) {         // Division
            runTwoOpCalc ( '/', divind );
        } 
    } while ( choice != 0 );
}


/*
 * Sub menu for matrix operations
 */
void matrixMenu () {
    int choice = 0;

    printMenuHeader ("Matrix Operations");
    printf ("1.Sum of Matrices\n");
    printf ("2.Transpose\n");
    printf ("3.Product of Matrices\n");
    choice = input ("Enter an operation command: ");

    switch ( choice ) {
        case 1: 
            matrix_sum ();
            break;
        case 2: 
            matrix_transpose ();
            break;
        case 3: 
            matrix_product ();
            break;
    }

}


/**
 * Sub menu for conversion operations
 */
void conversionMenu () {
    int choice = 0;

    printMenuHeader ("Conversion Menu");
    printf ("1.Temperature(1)\n");
    printf ("2.Time\n");
    choice = input ("Please choose an operation number:");

    switch ( choice ) {
        case 1: 
            temp ();
            break;
        case 2: 
            time ();
            break;
    }

}


/**
 * Runs the Scientific calculator menu and branches based on user input
 */
void runSciCalc () {
    float choice = 0, firstOp = 0, secondOp = 0, result = 0;

    do {
        printMenuHeader ("Scientific Calculator Menu");
        printf ("1.Power function (x^y)\n");
        printf ("2.Factorial Series (x!)\n");
        printf ("3.Fibonacci Series \n");
        printf ("4.Sine (Sin x)\n");
        printf ("5.Cosine (cos x)\n");
        printf ("6.Tangent (Tan x)\n");
        printf ("7.Cosec (cosec x)\n");
        printf ("8.Sec (sec x)\n");
        printf ("9.Cot (cot x)\n");
        printf ("10.Matrix functions\n");
        printf ("11.Conversion functions\n");
        printf ("0.Back\n");
        choice = input ("Select Menu: ");
        system ("clear");

        if ( choice == 1 ) {
            firstOp = input ("Enter base(x): ");
            secondOp = input ("Enter power(y): ");
            result = powerfn ( firstOp, secondOp );
            print ( "\nResult of", "^" , firstOp, secondOp, result);
        } else if ( choice == 2 ) {
            firstOp = input ("Enter numbers of term: ");
            result = fact (firstOp);
            spprint ( "\nFactorial of", "!" , firstOp, result );
        } else if ( choice == 3 ) {
            firstOp = input ("Enter numbers of term: ");
            result = fib (firstOp);
            spprint ( "\nFibonacci of", " ", firstOp, result );
        } else if ( choice == 4 ) {
            firstOp = input ("Enter your value: ");
            result = sine (firstOp);
            spprintf ( "\nSine of", " ", firstOp, result );
        } else if ( choice == 5 ) {
            firstOp = input ("Enter your value: ");
            result = cosine (firstOp);
            spprintf ( "\nCosine of", " ", firstOp, result );
        } else if ( choice == 6 ) {
            firstOp = input ("Enter your value: ");
            secondOp = sine (firstOp);
            result = cosine (firstOp);
            result = secondOp / result;
            spprintf ( "\nTangent of", " ", firstOp, result );
        } else if ( choice == 7 ) {
            firstOp = input ("Enter your value: ");
            result = sine (firstOp);
            spprintf ( "Cosec of", " ", firstOp, (1/result) );
        } else if ( choice == 8 ) {
            firstOp = input ("Enter your value: ");
            result = cosine (firstOp);
            spprintf ( "\nSec of", " ", firstOp, (1/result) );
        } else if ( choice == 9 ) {
            firstOp = input ("Enter your value: ");
            secondOp = sine (firstOp);
            result = cosine (firstOp);
            result = secondOp / result;
            spprintf ( "\nCot of", " ", firstOp, (1/result) );
        } else if ( choice == 10 ) {
            matrixMenu ();
        } else if ( choice == 11 ) {
            conversionMenu ();
        }
    } while ( choice != 0 );
}


/**
 * Main function - menu loop for the calculator application
 * @param argc Count of command line arguments supplied by the user
 * @param argv Array of strings of supplied user arguments
 * @return Integer value corresponding to program success - 0 on success
 */
int main ( int argc, char *argv[] ) {
    int menu = 0;

    do {
        printMenuHeader ("Menu");
        printf ("1.Regular Calculator\n");
        printf ("2.Scientific Calculator\n");
        printf ("3.Acountant Calculator\n");
        printf ("4.Read Help and Notice\n");
        printf ("0.Exit\n");
        menu = input ("Select Menu: ");
        system ("clear");

        if ( menu == 1 ) {
            runRegCalc ();
        } else if ( menu == 2 ) {
            runSciCalc ();
        }   
/******** End of Kevin's section ***********/
if(menu==3){

    warp:

        //system("clear");
        printf("\n===========================\n");
        printf("Accountant Calculator Menu\n");
        printf("===========================\n");
        printf("Please set value first\n");
        printf("\n"); 

    int n,i,j,amenu;
    float rest,max,min,x_bar=0,sum=0;
    float med,mod,count;
    int temp;

        n=input("Enter number of term: ");

    float set[n];
    int numtemp[n];

     for(i=0;i<n;i++){
        set[i]=inputAry("Enter value terms",i);
    }

     for(i=0;i<n;i++){
         for(j=0;j<=i;j++){
                 if(set[j]>set[i]){
                rest=set[j];
                set[j]=set[i];
                set[i]=rest;
             }
        }
    }

min = set[0];
max = set[n-1];

for(i=0;i<n;i++){
    sum+=set[i];
}
x_bar=(sum/n);

if((n%2)!=0){
    med=set[((n+1)/2)-1];
}
else{
    med=(set[((n+1)/2)]+set[((n+1)/2)-1])/2;
}

for(i=0;i<n;i++){
    numtemp[i]=0;
}
for(i=0;i<n;i++){
    temp=set[i];
    for(j=i;j<n;j++){
    if(set[j]==temp){
        numtemp[i]++;
    }
    }
}

temp=numtemp[0];
for(i=1;i<n;i++){
    if(numtemp[i]>temp){
        temp = numtemp[i];
    }
}

if(i==999){//Always False If

warp1://Warp form menu
j=0;

for(i=0;i<n;i++){
    if(numtemp[i]==temp){
        j++;
    }
}

if(j==1){
    for(i=0;i<n;i++){
    if(numtemp[i]==temp){
        printf("%.4f\n",set[i]);
    }
    }
}

else{
    printf("Not have mode value\n");    
}

}

     do{
        printf("\n===========================\n");
        printf("Accountant Calculator Menu\n");
        printf("===========================\n");
        printf("1.Show max\n");
        printf("2.Show min\n");
        printf("3.Show x-bar\n");
        printf("4.Show range\n");
        printf("5.Show Med\n");
        printf("6.Show Mode\n");
        printf("7.Show value(sort)\n");
        printf("8.Set new value\n");
        printf("0.Back\n");
        amenu = input("Select Menu: ");//input acountant  menu
        system("clear");

        if(amenu==1){
            printf("\n");
            Aryprint("Max is",max);
        }

        if(amenu==2){
            printf("\n");
            Aryprint("Min is",min);
        }

        if(amenu==3){
            printf("\n");
            Aryprint("X-bar is",x_bar);
        }

        if(amenu==4){
            printf("\n");
            Aryprint("Range is",max-min);
        }

        if(amenu==5){
            printf("\n");
            Aryprint("Med is",med);
        }

        if(amenu==6){
            printf("\n");
            printf("Mode is: ");
            goto warp1;
        }

        if(amenu==7){
            printf("\n");
            printf("Set of number is(sort): ");
            for(i=0;i<n;i++){
            printf("%.3f ",set[i]);
            }
        }

        if(amenu==8){
            goto warp;
        }

        }while(amenu!=0);
    }

    if(menu==4){
        char text;

            help = fopen("User_helping.txt","r");
        
            while((text=fgetc(help))!=EOF){
                fprintf(stdout,"%c",text);
            }

            fclose(help);
    }
}while(menu!=0);

return 0;
}

