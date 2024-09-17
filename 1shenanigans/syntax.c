/*
name: Amaiam ul Haque
date: Sept 6th, 2024
format: 7 lines before new topic, titles in all caps w/ 2 line gaps, 
*/

//STANDARD LIBRARIES
#include <stdio.h>  // input/out functions
#include <math.h>   
#include <string.h> 
#include <ctype.h>  //char handling functions
#include <time.h>   // manipulate time and date
#include <stdlib.h> // utility functions (conversions, dynamic memory allocation, sorting/searching, RNG)
//#include "selfMadeLibrary.h"

int topic1 (void){

    int num;
    printf(""); //aka formatted print
    scanf("%d", &num); //user input
    
    // CONVERSION SPECIFIERS
    // int = %d
    // char =  %c
    // float = %f
    // double = %f   for print
    // double = %lf  for scan
    // hexadec = %x
    
    //FOR LOOP
    int i, initial = 0, final = 8, increment = 2;
    for (i = initial; i < final; i += increment){ // for (variableType variable = initial value; terminating condition; increment)
        printf("");
    }

    //ARRAY
    int numBuffer[5]; // dataType variable [# of elements]
    
    return 0; 
    // return -1 = by convention, = failed upon startup
    // return -2 = maybe this means divide by zero
}



int topic2 (void){

    //FUNCTIONS
    //functionDataType functionName (paramaterDataType1 variableName1, paramaterDataType2 variableName2)
    //functionDataType functionName (paramaterDataType1, paramaterDataType2)

    const int constant;
    static int number; //automatically initialised to 0

    // library = header (prototypes) + source file (implementations)
    // must compile source file then main file.  eg. gcc ./mymath.c ./main.c -o main
    // both must have the same names and in the same folder as the main program

    //INTERNAL LINKAGE - global vars with 'static' in file A cant be referenced outside of file A
    //EXTERNAL LINKAGE - global var 'g' defined in file A can be referenced from file B, if 'g' is declared in B w/ 'extern specificier


}


int topic3 (void){

    //SPECIFY DATA SIZE FOR CONSTANTS
    //integer nums defaulted as int: 
    //          l/L = long
    //          u/U = unsigned
    //          ul/UL = unsigned long
    //floating pts defaulted as double: 
    //          f/F = float
    //          l/L = long double

    //acsii [0,127]
    printf("%c", 'a'); //prints a
    printf("%d", 'a'); //prints 97

    //UNARY OPERATOR: -, ++, --
    //PRE(IN/DE)CREMENT - in/decrements var's value before evals expression
    //POST(IN/DE)CREMENT - in/decrements var's value after evals expression
    //PRECEDENCE AND ASSOCIATIVITY: unary > binary: * > / > % > + > -

    //SWITCH CASE
    int num;
    switch (num){

        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }

}






/*
name: Amaiam ul Haque
date: 
summary:
*/

#include <stdio.h>

int main(void) {
    
    int i, input, sum = 0;

    for (i=0; i<10; i++){
        printf("Enter a number: ");
        scanf("%d", &input);
        if (input % 2 != 0)
            sum += input;
    }

    printf("The final sum of odd inputs = %d\n" , sum);


    float numBuf [15];

    for (i = 0; i<15; i++){
        printf("Enter a number: ");
        scanf("%lf", &numBuf[14-i]);
    }
    
    for (i = 0 ; i < 15; i++){
        printf("%f", numBuf[i]);
    }
    printf("%f", numBuf[i]);





    return 0; //type '$LASTEXITCODE' in terminal to figured out if it actually returned 0
}