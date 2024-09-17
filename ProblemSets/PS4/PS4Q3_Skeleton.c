#include <stdio.h>

#define N 3

int determinant(int param[])
{
    // implement 2x2 determinant.
    // param[0] = a
    // param[1] = b
    // param[2] = c
    // param[3] = d
}

void adjugate(int src[][N], int dst[][N])
{
    // Step 1: For every element in A, find its cofactor elements
    //  Hint: You will need a 2-level nested for loop inside ANOTHER 2-level nested for loop

    // Step 2: Calculate the cofactor determinant, write it into the corresponding element in C
    //  Hint: complete the determinant() implementation and use it for your benefit.

    // Step 3: Apply alternating signs 
    //  Hint: Use the even-odd pattern of i+j

    // Step 4: Transpose C to get adj(A)
    //  Hint: Q1 of Problem Set 4
}

// Use this function to print your matrix out for confirmation.
void printMatrix(int matrix[][N])
{
    int i, j;
    
    for(i = 0; i < N; i++) {     
        for(j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int source[N][N] = { {1, 3, 5}, {6, 4, 2}, {8, 7, 9} };
    int adjoint[N][N] = { 0 };

    printf("Source Matrix: \n");
    printMatrix(source);

    printf("Adjugate Matrix: \n");
    adjugate(source, adjoint);
    printMatrix(adjoint);
    
    return 0;
}