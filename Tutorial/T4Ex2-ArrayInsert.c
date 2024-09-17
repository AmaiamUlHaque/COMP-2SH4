#include <stdio.h>
#define SIZE 100

void InsertChar(char array[], int size, char thisChar)
{
    // Insert thisChar to the middle of the array
    // If size is odd, go for floored midpoint
    // Assume the incoming array always has room for extra characters
    int mid, i;
    mid = size / 2; //will automatically get floored since its integer division
    for (i = size; i >= mid; i--){ // i=size since we adding another element so needs additional index and array has the room for it
        array[i] = array[i-1];
    }
    array[mid-1] = thisChar;
}


int main(void)
{
    char charBuf[SIZE] = "*!**!*";
    int i, bufSize = 6;
    char input;

    do
    {
        fflush(stdin);
        printf("Give me a character (x to exit): \n");
        scanf("%c", &input);

        InsertChar(charBuf, bufSize++, input);

        printf("Updated Content is:\n");
        for(i = 0; i < bufSize; i++)
        {
            putchar(charBuf[i]);
        }
        putchar('\n');

    } while(input != 'x');

    return 0;
}
