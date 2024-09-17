//Write a C function that finds out the MIN and MAX of a signed short
//Hint – Start from 0, use a while loop


#include <stdio.h>

int main (void){

    //decrease until it becomes positive.
    //only works since -num have a the most significant bit as 1
    //so -num looks like 1XXX and +num looks like 0XXXX
    //even tho +num > -num, it does the counting in binary
    //eg. 3bit nums: -1,-2,-3,-4,3,2,1,0 = 111, 110, 101, 100, 011, 010, 001, 000
    //even tho decimal not in order, the binary is

    signed short int num=-1;
    while (num<0){
        num--;
    }

    printf("signed short MAX: %d\n", num);

    num++;
    printf("signed short MIN: %d\n", num);

    
    return 0;
}