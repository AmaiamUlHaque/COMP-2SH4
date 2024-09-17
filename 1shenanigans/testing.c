#include <stdio.h>


int main (void){

    int arr [3][2][4];

    int i,j,k;
    for (i=0; i<(3*2*4); i++){
        printf("element address: %p\n", &arr[0][0]+i);
    }

    printf("\nNEXT PRINT THINGY\n\n");

    for (i=0; i<3; i++){
        for (j=0; j<2; j++){
            for (k=0; k<4; k++){

                printf("element address: %p\n", &arr[i][j][k]);

            }
        }
    }

    return 0;
}
