#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []) {
    //int size = sizeof(mat);
    int size = N3-1;
    int i=0,j=0,n=0,k=0,index=0;
    do {
        for (i = k; i <= n; i++){
            arr[index] = mat[i][n-j];
            index++;
            j++;
        }
        j=0;
        (n<size)? n++: k++; //if false, then that mean n=size, so must increase k instead
    } while (k<=size);
}
