//COVERT FROM ONE LINE STATEMENTS USING COMMA OPERATORS TO MULTI LINE STATEMENTS WITHOUT COMMA OPERATORS
//AND THE REVERSE
//You can assuming x = 10, y = 10;


#include <stdio.h>

int main (void){

    //Given the following one line statements, do this in without using comma operators
    int x=10, y=10;
    y = (x += 3, printf("x=%d, y=%d\n", x, y), x += 4, y += 6, printf("x=%d, y=%d\n", x, y), x + y, x + 2*y);
    printf("Original Value:\t\tx: %d, y: %d\n", x,y);

    x=10, y=10;
    x+=3;
    printf("x=%d, y=%d\n", x, y);
    x+=4;
    y+=6;
    printf("x=%d, y=%d\n", x, y);
    //y=x+y; EXLCUDE THIS ONE, ONLY LAST STATEMENT ASSIGNED TO Y
    y=x+2*y;
    printf("Expanded Value:\t\tx: %d, y: %d\n", x,y);


    //Given the following sequential statements, do this in one line using comma operators
    int input;
    x=10, y=10;
    y = x / 5;
    x = y + 3;
    scanf("%d", &input);
    x = y % input;
    input = 2*x + 5*y;
    printf("Original Value:\t\tx: %d, y: %d\n", x,y);

    x=10, y=10;
    input = (y=x/5, x=y+3, scanf("%d", &input), x=y%input, 2*x+5*y);
    printf("Condensed Value:\tx: %d, y: %d\n", x,y);

    return 0;
}