//Develop a function that adds all the digits of the positive input integer and returns the result. 
//Write a main program to test this function.
//Example, if the input integer is 983 then the function should return 20 (9+8+3 = 20).


#include <stdio.h>

int DigitsSum (int num){
    int sum=0;

    while (num > 0){ //takes least significant digit, add it to sum, then remove it
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main (void){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("the digits sum up to %d", DigitsSum(x));
    
    return 0;
}