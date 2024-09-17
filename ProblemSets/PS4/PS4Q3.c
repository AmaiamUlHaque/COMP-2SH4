#include <stdio.h>

#define N 3

int determinant(int param[])
{
    // implement 2x2 determinant.
    // param[0] = a
    // param[1] = b
    // param[2] = c
    // param[3] = d
    return (param[0] * param[3] - param[1] * param[2]);
}

void adjugate(int src[][N], int dst[][N])
{
    int i, j, k, l, temp = 0, value = 0, count = 0;
    int param[4] = {0};
		
	// Step 1: For every element in A, find its cofactor elements
    //  Hint: You will need a 2-level nested for loop inside ANOTHER 2-level nested for loop
    for(i = 0; i < N; i++) {     // first two nested for-loops for 
        for(j = 0; j < N; j++) { // iterating through 3x3 matrix elements
	        
            count = 0;
            for(k = 0; k < N; k++) {  // second nested for-loops for finding cofactor elements for determinant
                for(l = 0; l < N; l++) {                    
                    if(i != k && j != l) 
                    {
                        param[count++] = src[k][l];  
                    }
                }
            } 
            
            // Step 2: Calculate the cofactor determinant, write it into the corresponding element in C
            //  Hint: complete the determinant() implementation and use it for your benefit.
            value = determinant(param);

            // Step 3: Apply alternating signs 
            //  Hint: Use the even-odd pattern of i+j
            if((i + j) % 2 != 0) value *= -1;  // alternating negative sign

            dst[i][j] = value;  // this is now the cofactor matrix            
        }
    }

    // Step 4: Transpose C to get adj(A)
    //  Hint: Q1 of Problem Set 4
    for( i = 0; i < N; i++ )
    {
        for( j = 0; j < i; j++ )
        {
            // Swapping anti-diagonal elements 
            temp = dst[i][j];
            dst[i][j] = dst[j][i]; 
            dst[j][i] = temp;
        }
    }


}

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
