//matrix transpose

#include <stdio.h>

#define N 10
int symmetric(double matrix[][N]) {

    //check if [i][j] == [j][i]
    int result = 1; // true
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = i + 1; j < N; j++) {
            if(matrix[i][j] != matrix[j][i]){
                result = 0; // false
                break;
            }
        }
    }
    return result;

}

int main (void){
    
    
    return 0;
}