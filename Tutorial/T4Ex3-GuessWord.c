#include <stdio.h>
#define SIZE 7
#define ROUND 10

int main(void)
{
    char charBuf[SIZE] = "insert";
    int i;
    char input;

    for(i = 0; i < ROUND; i++ )
    {
        fflush(stdin);
        printf("Take a Guess: \n");
        scanf("%c", &input);

        // Develop a switch-case statement to determine whether the input is in the charBuf.
    }

    printf("Say the word now!\n");

    return 0;
}
