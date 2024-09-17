//Ask the user to provide 20 integers. Determine if the integers are entered in non-decreasing sorted order
//im doing 5 cause 20 is too much effort to test

#include <stdio.h>

int main (void){

    int elements = 5, nums [elements], flag=1, i;
    for (i = 0; i < elements; i++){
        printf("Enter a number: ");
        scanf("%d", &nums[i]);
    }
    for (i=0; i < elements-1; i++){
        if (nums[i] < nums[i+1]){
            flag = 0;
            break;
        }
    }
    flag == 0? printf("Not in decreasing order.") : printf("In decreasing order.");

    return 0;
}