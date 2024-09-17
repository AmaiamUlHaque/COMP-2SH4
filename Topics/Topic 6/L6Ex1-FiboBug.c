#include <stdio.h>

int findFibo(int N)
{
    int prevTerm = 1;
    int currTerm = 1;
    int temp = 0;
    int i;

    for(i = 0; i <= N; i++)
    {
	    temp = currTerm;
	    currTerm += prevTerm;
  	    prevTerm = temp;
    }

    return currTerm;
}

int main(void)
{
    int input;
    printf("Which Fibo Term? >> ");
    scanf("%d", &input);
    printf("Fibo Term %d = %d\n", input, findFibo(input));
    return 0;
}