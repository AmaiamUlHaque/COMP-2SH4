//header: 
//name
//date
//summary

#include <stdio.h>

int main (void){ //signature of function
    
    //all code must have ; at the end, so no indents necessary but good practice + readability, 
    //except for library stuff (preprcessor directive)

    //each piece of info stored in 'memory slot', each slot has a 'memory address'
    //variable declaration = find memory slot fitting data type size, associate memory with that variable's name, enforce data types it can take

    int num;
    printf(""); //aka formatted print
    scanf("%d", &num); //takes user input and expects 'int' and stores into num

    //FOR LOOP
    int i, initial = 0, final = 8, increment = 2;
    for (i = initial; i < final; i += increment){
        // for (variableType variable = initial value; terminating condition; increment)
        printf("idk, thing for for loop");
    }

    //C Primitive Array
    int numBuffer[4]; // dataType variable [# of elements]
    //primitive = stores only one data type
    //array name always refers to the adress of the first element

    return 0; //indicates program ran successfully
}