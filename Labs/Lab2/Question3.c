#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], struct Q3Struct effVector[], int size) {
    //puts it into efficient form
    int i, index = 0;
    for (i=0; i < size; i++){
        if (source[i] != 0){
            effVector[index].pos = i;
            effVector[index].val = source[i];
            index++;
        }
    }
}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n) {
    //puts it back into original form
    //already checked that the array source has already been initialised to all 0's
    int i;
    for (i=0; i<n; i++){
        source[effVector[i].pos] = effVector[i].val;
    }
}
