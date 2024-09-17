
#include <stdio.h>
#include "mymath.h"

int main(void)
{
    int num1, num2;
    int result = 0;

    printf("\nPlease enter integer 1: ");
    scanf("%d", &num1);
    printf("Please enter integer 2: ");
    scanf("%d", &num2);
    printf("The integers you entered are: %d and %d\n", num1, num2);

    result = add(num1, num2);
    printf("%d + %d = %d\n", num1, num2, result);
    result = subtract(num1, num2);
    printf("%d - %d = %d\n", num1, num2, result);
    result = multiply(num1, num2);
    printf("%d x %d = %d\n", num1, num2, result);
    result = divide(num1, num2);
    printf("%d / %d = %d\n", num1, num2, result);
    
    return 0; // Good habit to end main with return 0 to show success.
}
