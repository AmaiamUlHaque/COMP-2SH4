//Determine whether the user-provided integer is a prime number

#include <stdio.h>

int main (void){
    
    int num, divisible = 0, i=0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 2 ; i < num; i++){
        if (num % i == 0) {
            (divisible = 1);
            break;
        }
    }

    if(divisible == 1) printf("%d is NOT prime number.", num);
    else printf("%d is a prime number.", num);

    return 0;
}
