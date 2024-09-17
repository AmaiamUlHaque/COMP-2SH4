//Develop a function that prints out all the factors of the provided integer and returns the number of factors. 
//Write a main program to test this function.


#include <stdio.h>

int factors (int num){
    int i=0, count=0;

    for (i=1; i<=num;i++){ //DONT I=0, THEN IT WONT GO INTO LOOP
        if (num%i==0){
            count++;
            printf("%d\n", i);
        }
    }
    return count;
}

int main (void){
    int x = 10;
    int count = factors(x);
    printf("# of factors of %d: %d", x, count);

    return 0;
}
