//TOPIC 15 - RECURSION

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){

    //PLV 15.1 - Call Stack

        //a conceptual thingy for hierarchy of function calls
            //basically to understand how functions are called

        //when function is called...
            //input parameters pushed onto stack
            //control halts at function invocation statement until finished
            //the return location from the function back to the invoker also on stack
                //basically where to go to once the function is done (ie. where it stopped at)
            //the return value from the function backto the invoker also on stack
                //the value resulting from the function will take the place of the return location as an r-value



    //15.0 - recursion

        //litterly just recursion --> using current value for the next calculation
            //ie. function calling itself
        
        //great for...
            //iterating thru structured list
            //sorting algorithms
            //program size/memory restrictions
            //faster stack response(hardware dependant)
        
        //iffy example
            //they both do the same thing
            NotRecurPrint(3);
            RecurPrint(3);
        
        //proper example - factorial
        // n! = n * n-1 * n-2 * n-3 * ... * 3 * 2 * 1
        //      n * (n-1)!
        // 0! = 1

        //recursion can go on infinitely --> need something to stop it where we want it to
            //via base case or termination clause
        
            //BASE CASE
                //a case where the function will not recurse
                //achieved via conditional statements

    return 0;

}

//FORMAT / GUIDELINE
/*
int RecursiveFunction (int x) {

    //base case / termination clause
    if (condition1)
        return value1;

    else if (condition2)
        return value2;


    //pre termination stuff
    RecursiveFunction(expression made of x)
    //post termination stuff
}
*/


//examples

void NotRecurPrint(int input){
    for (int i = 0; i<input; i++){
        printf("Hi from #%d\n");
    }
}

void RecurPrint(int input){
    if (input==0){ //base case
        return;
    }
    RecurPrint(input-1);
    printf("Hi from #%d\n");
}


int factorial(int n){
    if (n == 0) //base case?
        return 1;
    else if(n == 1) //base case
        return 1;
    else
        return (n * factorial(n-1));
}

