#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

// void sortDatabyBubble(struct Q4Struct array[], int size);

// int main (void){
//     int n=6;
// 	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
// 	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
// 	sortDatabyBubble(input, n);
//     //struct Q4Struct actual[]={{10, 'c'}, {10, 'c'}, {10, 'c'}, {12, 'z'}, {77, 'a'}, {77, 'a'}};
// }

void sortDatabyBubble(struct Q4Struct array[], int size) {
    struct Q4Struct temp;
    temp.intData = 0;
    temp.charData = 0;

    int i;
    int curr, next;
    int done = 0;

    while(!done) {
        done = 1;
        
        for(i = 0; i < size - 1; i++) { 
            curr = array[i].intData;
            next = array[i + 1].intData;

            if(curr > next) {
                temp.intData = array[i].intData;
                temp.charData = array[i].charData;

                array[i].intData = array[i + 1].intData;
                array[i].charData = array[i + 1].charData;

                array[i + 1].intData = temp.intData;
                array[i + 1].charData = temp.charData;

                done = 0;
            }
        }
    }    
}


void sortDatabySelection(struct Q4Struct array[], int size) {

    // int i, j, SI=0; //SI = smallest index
    // int tempI;
    // char tempC;
    // for (i=0; i<(size-1); i++){

    //     SI = i;
    //     for (j=i; j<size; j++){
    //         if (array[SI].intData > array[j].intData){
    //             SI = j;
    //         }
    //     }

    //     //swap array[IS] and array[i]
    //     tempI = array[SI].intData;
    //     tempC = array[SI].charData;
    //     array[SI].intData = array[i].intData;
    //     array[SI].charData = array[i].charData;
    //     array[i].intData = tempI;
    //     array[i].charData = tempC;
    // }
}

