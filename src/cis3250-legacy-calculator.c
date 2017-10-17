/**
* 
* MADDIE'S CHANGES BEGIN
*
*/

// CHANGED: October 14 by Maddie. Changed order of #includes for clarity.
// CHANGED: October 14 by Maddie. All pointer declarations of form "type *var"
// CHANGED: October 14 by Maddie. Added doxygen style comments above each function.
// CHANGED: October 14 by Maddie. Moved all brackets to same line for functions.
// CHANGED: October 14 by Maddie. All function parameters of form: "( type var )"
// CHANGED: October 14 by Maddie. Initialized all floats to 0.0, ints to 0
// CHANGED: October 14 by Maddie. Fixed all indentation (4 spaces)/loops/if statements to coding convention.
// CHANGED: October 14 by Maddie. Changed printf/scanf parameters to format "scanf("%f", &key)"
// CHANGED: October 14 by Maddie. Changed calculations to format: "result = multer * multin;"
// CHANGED: October 14 by Maddie. Changed comparisons to format: "var == 0"
// CHANGED: October 14 by Maddie. Moved variable initializations to their own lines

// CHANGED: October 14 by Maddie. CHANGED VARIABLE NAME inName to inName (camel case).
// CHANGED: October 14 by Maddie. CHANGED VARIABLE NAME addIn to addIn (camel case).
// CHANGED: October 14 by Maddie. CHANGED VARIABLE NAME minin to minIn (camel case).
// CHANGED: October 14 by Maddie. CHANGED VARIABLE NAME multin to multIn (camel case).
// CHANGED: October 14 by Maddie. CHANGED VARIABLE NAME dividin to dividIn (camel case).

// CHANGED: October 14 by Maddie. CHANGED FUNCTION NAME Aryprint to aryPrint (camel case).

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "factorial.h"
#include "matrices.h"
#include "powerfunction.h"
#include "conversions.h"

#define PI 3.1415926535897932384626433832795

FILE *help;

/**
* Function to receive user input
*
* @param char * variable "inName" (string prompt to print for user)
* @return float value of "key" variable from user
*/
float input( char *inName ) {
   
    float key = 0.0;
    char temp[9999];

    do {

        printf("%s", inName);

        if( !scanf("%f", &key) ) {
            scanf("%s", &temp); //recieve temp
            printf("Please try again!\n");
        } else {
            return key;
    	}

	} while( 1 );	

}

/**
* Function to get array input from user.
*
* @param char * variable "inName" (string prompt to print for user)
* @param int variable "num" (for fibonacci sequence)
* @return float value of "key" variable from user
*/
float inputAry( char *inName, int num ) {
	
    float key = 0.0;
	char temp[9999];

    do {

        printf("%s[%d]: ", inName, num+1);

        if( !scanf("%f", &key) ) {
            scanf("%s", &temp);
            printf("Please try again!\n");
        } else {
            return key;
        }

    } while( 1 );	

}

/**
* Function to add 2 float values.
*
* @param float variable "adder" to be added with "adder"
* @param float variable "addIn" to be added with "adder"
* @return float value result of addition
*/
float plus( float adder, float addIn ) {

	float result = 0.0;
	result = adder + addIn;
	return result;

}

/**
* Function to subtract 2 float values.
*
* @param float variable "miner" to subtract "minIn" from
* @param float variable "minIn" to subtract from "miner"
* @return float value result of subtraction
*/
float minus( float miner, float minIn ) {

	float result = 0.0;
	result = miner - minIn;
	return result;

}

/**
* Function to multiply 2 float values.
*
* @param float variable "multer" to multiply with "multIn"
* @param float variable "multIn" to multiply with "multer"
* @return float value result of multiplication
*/
float mult( float multer, float multin ) {

	float result = 0.0;
	result = multer * multin;
	return result;

}

/**
* Function to divide 2 float values.
*
* @param float variable "divider" to divided by with "dividIn"
* @param float variable "dividIn" to divide "divider" by
* @return float value result of division
*/
float divind(float divider,float dividIn) {

	float result = 0.0;
	result = divider/dividIn;
	return result;

}

/**
* Function to calculate factorial
*
* @param integer "term" to calculate factorial of
* @return integer factorial result (once finished recursively calling function) 
*/
int factorial( int term ) {

    if( term == 0 ) {
        return 1;
    }

	return term * factorial( term-1 );

}

/**
* Function to calculate fibonacci sequence
*
* @param integer "term" to calculate fibonacci sequence of
* @return integer fibonacci sequence result (once finished recursively calling function) 
*/
int fib( int term ) {
	
    if( term == 1 ) {
		return 0;
	}

	if( term == 2 ) {
		return 1;
	}

	return fib( term-1 ) + fib( term-2 );

}

/**
* Function to calculate the nth power of a given number
*
* @param float value base (base of exponent calculation)
* @param integer value pow (power to raise base to)
* @return float base to the nth power
*/
float power( float base, int pow ) {

	int i = 0;
	float mem = 1.0;

	for( i=0; i<pow; i++ ) {
		mem *= base;
	}

	return mem;

}

/**
* Function to calculate sine value of given float
*
* @param float radius to calculate sine of
* @return float calculated sine value of given radius
*/
float sine( float radius ) {
	
    float val = 0.0;
    float sin = 0.0;
	
    val = radius * (PI/180);
	sin = val - (power( val, 3 ) / factorial(3)) + (power( val, 5 ) / factorial(5)) - (power( val, 7 ) / factorial(7));
	
    return sin;

}

/**
* Function to calculate cosine value of given float
*
* @param float radius to calculate cosine of
* @return float calculated cosine value of given radius
*/
float cosine( float radius ) {
	
    float val = 0.0;
    float cos = 0.0;

	val = radius * (PI/180);
	cos = 1 - (power( val, 2 ) / factorial(2)) + (power( val, 4 ) / factorial(4)) - (power( val, 6 ) / factorial(6));
	
    return cos;

}

/**
* Function to print formatted output of caluculations where input/result are integers
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param int ini :: initial value being calculated
* @param int res :: value of result of calculation
* @return integer zero
*/
int spprint( char *screen, char *sym, int ini, int res ) {
	
    printf("%s %d%s = %d\n", screen, ini, sym, res);
    return 0;

}

/**
* Function to print formatted output of caluculations where input/result are floats
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param float ini :: initial value being calculated
* @param float res :: value of result of calculation
* @return float zero
*/
float spprintf( char *screen, char *sym, float ini, float res ) {
	
    printf("%s %.4f%s = %.4f\n", screen, ini, sym, res);
    return 0;

}

/**
* Function to print formatted output of regular calculator menu calculations
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param float ini :: initial value being calculated
* @param float ini :: initial upt being calculated
* @param float res :: value of result of calculation
* @return float zero
*/
float print( char *screen, char *sym, float ini, float upt, float res) {

	printf("%s %.4f %s %.4f = %.4f\n", screen, ini, sym, upt, res);
    return 0;

}

/**
* Function to print formatted output of accounting calculator menu calculations
*
* @param char * screen :: to print before result given
* @param float ans :: value of answer of the calculation
* @return float zero
*/
float aryPrint( char *screen, float ans ) {

	printf("%s : %.4f\n", screen, ans);
    return 0;
    
}
/**
* 
* MADDIE'S CHANGES END
*
*/


int main(int argc,char*argv[])
{
	float a,b,c;
	float r1,r2;
	char sym;
	int menu,rmenu,smenu;


do{
	printf("\n======\n");
	printf("Menu\n");
	printf("======\n");
	printf("1.Regular Calculator\n");
	printf("2.Scientific Calculator\n");
	printf("3.Acountant Calculator\n");
	printf("4.Read Help and Notice\n");
	printf("0.Exit\n");
	menu = input("Select Menu: ");//input main menu
	system("clear");

if(menu==1){

do{
	printf("\n======================\n");
	printf("Regular Calculator Menu\n");
	printf("=======================\n");
	printf("1.PLUS\n");
	printf("2.MINUS\n");
	printf("3.MULTIPLY\n");
	printf("4.DIVIDE\n");
	printf("0.BACK\n");
	rmenu = input("Select Menu: ");//input regular  menu
	system("clear");


	if(rmenu==1){
		a=input("Enter value 1 st: ");
		b=input("Enter value 2 nd: ");
		c=plus(a,b);
		printf("\n");
		print("sum of","plus",a,b,c);
	}

	if(rmenu==2){
		a=input("Enter value 1 st: ");
		b=input("Enter value 2 nd: ");
		c=minus(a,b);
		printf("\n");
		print("result of","minus",a,b,c);
	}

	if(rmenu==3){
		a=input("Enter value 1 st: ");
		b=input("Enter value 2 nd: ");
		c=mult(a,b);
		printf("\n");
		print("result of","x",a,b,c);
	}

	if(rmenu==4){
		a=input("Enter value 1 st: ");
		b=input("Enter value 2 nd: ");
		c=divind(a,b);
		printf("\n");
		print("result","/",a,b,c);
	}

}while(rmenu!=0);
}

if(menu==2){

	do{
		printf("\n===========================\n");
		printf("Scientific Calculator Menu\n");
		printf("===========================\n");
		printf("1.Power function (x^y)\n");
		printf("2.Factorial Series (x!)\n");
		printf("3.Fibonacci Series \n");
		printf("4.Sine (Sin x)\n");
		printf("5.Cosine (cos x)\n");
		printf("6.Tangent (Tan x)\n");
		printf("7.Cosec (cosec x)\n");
		printf("8.Sec (sec x)\n");
		printf("9.Cot (cot x)\n");
		printf("10.Matrix functions\n");
		printf("11.Conversion functions\n");
		printf("0.Back\n");
		smenu = input("Select Menu: ");
		system("clear");

	if(smenu==1){
		a=input("Enter base(x): ");
		b=input("Enter power(y): ");
		c=powerfn(a,b);
		printf("\n");
		print("result of","^",a,b,c);
	}

	if(smenu==2){
		a=input("Enter numbers of term: ");
		c=fact(a);
		printf("\n");
		spprint("Factorial of","!",a,c);
	}

	if(smenu==3){
		a=input("Enter numbers of term: ");
		c=fib(a);
		printf("\n");
		spprint("Fibonacci of"," ",a,c);
	}

	if(smenu==4){
		a=input("Enter your value: ");
		c=sine(a);
		printf("\n");
		spprintf("Sine of"," ",a,c);
	}

	if(smenu==5){
		a=input("Enter your value: ");
		c=cosine(a);
		printf("\n");
		spprintf("Cosine of"," ",a,c);
	}

	if(smenu==6){
		a=input("Enter your value: ");
		r1=sine(a);
		r2=cosine(a);
		c=r1/r2;
		printf("\n");
		spprintf("Tangent of"," ",a,c);
	}

	if(smenu==7){
		a=input("Enter your value: ");
		c=sine(a);
		printf("\n");
		spprintf("Cosec of"," ",a,1/c);
	}

	if(smenu==5){
		a=input("Enter your value: ");
		c=cosine(a);
		printf("\n");
		spprintf("Sec of"," ",a,1/c);
	}

	if(smenu==8){
		a=input("Enter your value: ");
		r1=sine(a);
		r2=cosine(a);
		c=r1/r2;
		printf("\n");
		spprintf("Cot of"," ",a,1/c);
	}

	if(smenu==10){
		int operation_number=0;
		       printf("\n\t\tSum of Matrices(1)\t\tTranspose(2)\t\tProduct of Matrices(3)");
       printf("\n\tEnter an operation command:");
       scanf("%d",&operation_number);

      switch(operation_number){
       case 1: matrix_sum();break;
       case 2: matrix_transpose();break;
       case 3: matrix_product();break;
       }
	}

	if(smenu==11){
		int operation_number=0;
		        printf("\n\n\n\t\tTemperature(1)\t\tTime(2)");
        printf("\n\n\n\t\tPlease choose an operation number:");
        scanf("%d",&operation_number);

        switch(operation_number){
            case 1: temp();break;
            case 2: time();break;
        }
        break;

	}



}while(smenu!=0);
}

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
			aryPrint("Max is",max);
		}

		if(amenu==2){
			printf("\n");
			aryPrint("Min is",min);
		}

		if(amenu==3){
			printf("\n");
			aryPrint("X-bar is",x_bar);
		}

		if(amenu==4){
			printf("\n");
			aryPrint("Range is",max-min);
		}

		if(amenu==5){
			printf("\n");
			aryPrint("Med is",med);
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



