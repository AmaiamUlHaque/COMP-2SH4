//SCANF TECHNIQUES
// Write a function that accepts the name + birthday input in the following format:
// • 31/01/1999 O
// And print the collected info out in the format of:
// • Birthday: January 31, 1999
// • Age: 25
// • Blood Type: O

#include <stdio.h>

int main (void){
    int day, month, year;
    char blood, m;
    printf("Enter your birthday and blood type in this format: DD/MM/YYYY B\nExample: 31/01/1999 O");
    scanf("%d/%d/%d %c", &day, &month, &year, &blood);

    printf("\nBirthday: ");
    switch (month){
        case 1: printf("January"); break;
        case 2: printf("February"); break;
        case 3: printf("March"); break;
        case 4: printf("April"); break;
        case 5: printf("May"); break;
        case 6: printf("June"); break;
        case 7: printf("July"); break;
        case 8: printf("August"); break;
        case 9: printf("September"); break;
        case 10: printf("October"); break;
        case 11: printf("November"); break;
        case 12: printf("December"); break;
        default: printf("invalid month"); break;
    }

    printf(" %d, %d\n", day, year);
    printf("Age: %d\n", 2024-year);
    printf("Blood Type: %c\n", blood);

    return 0;
}