#include <stdio.h>

// First of all, why don't we need the string size?
void reverse(char str[]) {
    // step 1 - find string size
    int size;
    for (size = 0; str[size] != '\0'; size++);


    // step 2 - deploy "half traversal" string reversal algorithm
    int i;
    char temp; 
    int mid = size/2;

    for (i = 0; i < mid; i++){
        temp = str[mid-i-1];
        str[mid-i-1] = str[mid+i];
        str[mid+i] = temp;
    }
}


int main(void){

    // char myStr[50] = "McMaster Electrical and Computer Engineering";   // 44 + 1 char string, but I used a larger buffer
    // printf("String before reverse: %s\n", myStr);
    // reverse (myStr);
    // printf("String after reverse: %s\n", myStr);

    char myStr[50];
    puts("Give me a string: ");
    gets(myStr);
    reverse (myStr);
    puts("after reverse: ");
    puts(myStr);

    return 0;
}


