#include <stdio.h>
#include <ctype.h> // character handling library
#include <string.h> // string handling library

int main (void){

    //C STRINGS
    
    //STRING CONSTANTS/LITTERALS
    //sequence of chars with double quotes
    //represesnted in memory as array of chars terminated with null char '\0'
    //eg. "hello" is 6 element array = {'h' 'e' 'l' 'l' 'o' '\0'}
    //eg. "A" is string {'A' '\0'}
    //    'A' is char constant

    char chArray [5] = {'h','e','l','l','o'};
    char myString[6] = {'h','e','l','l','o','\0'}; //only this considered string
    char string2 [6] = "hello";
    //both myString and string2 both have array size of 6 but string size of 5




    
    //computing string size
    char b [] = "blue";
    int i = 0;
    int size = 0; //not necessary, since i do the same thing

    while (b[i] != '\0'){
        printf("character: %c", b[i]);
        size++;
        i++;
    }

    //can also
    for (i = 0; b[i] != '\0'; i++){};


    int counter=0;
    char word[] = "Programming at McMaster is fun!";
    while (b[i]!='\0'){
        if (b[i] == 'm' || b[i] == 'M'){
            counter++;
        }
    }

    //strings are pass by reference ie. genuine value is modified




    //string handling - console io
    char myStr [50];
    scanf("%s", myStr); //arrays dont need "&" since the & finds the address but an array's name is already its adress
    scanf("%49s", myStr); //tells scamf how many chars to expect, anything after that is cut off
    //otherwise might cause segmentation fault

    //%fieldWidth.precisions
    //eg. %10.5s = output space is 10 chars and will only output the first 5 chars and whitespace pad the rest


    //sscanf(""); //obtain input  from another string
    //sprintf(""); //idk honestly


    //gets(char array) = reads next input line until 'enter pressed which is regsitered as \n and is replaced by '\0' then stored into char array
    //puts(string) = prints all chars of string, /n is appended at end instead of '\0'


    // <ctype.h> is char handling library
    int isdigit(int c);  //Determine if c is a digit
    int isalpha(int c);  //Determine if c is a letter
    int islower(int c);  //Determine if c is a lowercase letter (True) or uppercase letter (False)
    int toupper(int c);  //Convert c to uppercase letter
    int tolower(int c);  //Convert c to lowercase letter
    int isxdigit(int c); //Determine if c is a hexadecimal digit (A-F, a-f, 0-9

    //<string.h> is string handling library
    // Copying string data
    // Concatenate strings
    // Comparing strings
    // Determining the length of a string (strlen)
    // Searching strings for characters and other sub-strings
    
    char letter;

    //Obtaining input from another string / character array
    //sscanf(); 
    sscanf(myStr, "%c", &letter);

    //Print output string into another string / character array
    //sprintf();
    sprintf(myStr, "%c", &letter);



    return 0;
}

