#include <stdio.h>
#define SIZE 10

void printVector(int [], int);
void addVector(const int [], const int [], int [], int);


int main(void) {

    // 1. Initialization
    //int size = 10; isnt as efficient as define SIZE 10, also variables are not constant, space in arrays are constant
    int vector1[SIZE] = {5, 8, 3};
    int vector2[SIZE] = {2, 3, 5};
    int resultVec[SIZE] = {0};

    // 2. Print Vector
    printVector(vector1, SIZE);
    printVector(vector2, SIZE);

    // 3. Design a function that finds the sum of two vectors and return it to resultVec.
    addVector(vector1, vector2, resultVec, SIZE);


    // 4. Print Result Vector    
    printVector(resultVec, SIZE);

    return 0;
}

void printVector(int vector[], int size){
    int i;
    printf("Vector: ");
    for (i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void addVector(const int vector1[], const int vector2[], int result[], int size) {
    int i;
    for (i = 0; i < size; i++){
        result[i] = vector1[i] + vector2[i];
    }
}