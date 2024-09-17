// Given 5 input numbers (integers), print out all the possible two-number combinations
// (i.e. calculating 2C5)


#include <stdio.h>

int main (void){
    
    int i, nums[5], j;

    for (i = 0; i < 5; i++){
        printf("Enter a number: ");
        scanf("%d", &nums[i]);
    }

    int min = 0;
    for (i = 0; i < 5; i++){
        for (j = min; j < 5 ; j++){
            printf("%d%d \n", nums[i], nums[j]);
        }
        min++;
    }
    
    return 0;
}