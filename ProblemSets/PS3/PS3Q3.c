//DEBUGGING
//The following code snippet contains multiple bad practices and logic mistakes that will not be captured
//by the compiler syntax checker. Apply the aforementioned coding tips to root out these bugs.
// • Intended Function: 
//      • Values below 10 considered too low, above 20 considered too high
//      • Value 15 is the answer, Value 14 or 16 considered close enough
//      • Otherwise, no hint message


#include <stdio.h>

int main (void){

    int input;

    //ORIGINAL
    input = 0;
    printf("Provide Integer: ");
    scanf("%d", &input);
    if(input > 10)
    if(input > 20) printf("Response Too High. \n");
    else if(input = 15) printf("Response Exactly Correct. \n");
    else if( (input = 14) || (input = 16) ) printf("Response Very Close. \n");
    else printf("Response Too Low. \n");

    

    printf("DEBUGGED VERSION:");
    //DEBUGGED
    input = 0;
    printf("Provide Integer: ");
    scanf("%d", &input);
    if(input > 10) {
        if(input > 20) {
            printf("Response Too High. \n");
            }
        else if(input == 15) {
            printf("Response Exactly Correct. \n");
        }
        else if ((input == 14) || (input == 16)) {
            printf("Response Very Close. \n");
        }
    }
    else {
        printf("Response Too Low. \n");
    }
    
    return 0;
}