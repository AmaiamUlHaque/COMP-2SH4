#include <stdio.h>

int isLarger(int a, int b)
{
    return a > b;
}

int isSmaller(int a, int b)
{
    return a < b;
}

int main(void)
{
    int data[20] = {1, 2, 5, 91, 7, \
                    4, 2, 7, 45, 7, \
                    2, 12, 8, 59, 41, \
                    5, 83, 13, 25, 6};

    int input;
    int i = 0;

    printf("Give me an integer >> ");
    scanf("%d", &input);

    // Go through every data element and check its relative size to the input
    //  If data element > input, replace element with input*2
    //  If data element < input, replace element with input/2
    // Stop the replacement process if an element is found to be the same as input
    // OR the end of the array has been reached.
    //
    // However, the actual behaviour of the program is SEGFAULT. :(
    //
    // DO NOT CHANGE THE DO-WHILE LOOP STRUCTURE.
    // FIX THE CODE WITH MINIMUM CHANGES.
    do
    {        
        if(isLarger(input, data[i]))
            data[i] = input * 2;
        else if(isSmaller(input, data[i]))
            data[i] = input / 2;
    }  
    while(data[i++] = input);    

    return 0;
}