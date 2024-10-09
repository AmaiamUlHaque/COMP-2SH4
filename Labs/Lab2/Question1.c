#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "Questions.h"


void add_vectors(double vector1[],double vector2[],double vector3[],int size) {//vector addition
	int i;
	for (i = 0; i < size; i++){
		vector3[i] = vector1[i] + vector2[i]; 
	}
}

double scalar_prod(double vector1[],double vector2[],int size) { //calculates the scalar product
    double prod=0;
	int i=0;
	for (i = 0; i < size; i++){
		prod += (vector1[i]) * (vector2[i]); 	
	}
    return prod;
}

double norm2(double vector1[], int size) { //calculates the L2 norm of the passed vector
    double L2;
	L2 = scalar_prod(vector1, vector1, size);
	L2 = sqrt(L2);
    return L2;
}
