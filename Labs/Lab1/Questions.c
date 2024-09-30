
#include "Questions.h"


//QUESTION 1
int Q1_for(int num){
	int sum = 0, i = 1;
	int max = 1000/num; //finds largest multiple
	for (i = 1; i <= max; i++){
		sum += i*num;
	}
	return sum;
}

int Q1_while(int num){
	int sum = 0, i = 1;
	int max = 1000/num;
	while(i <= max){
		sum += i*num;
		i++;
	}
	return sum;
}

int Q1_dowhile(int num){ 
	int sum = 0, i = 0; //changed i = 0 instead of 1, since if num is not [0,1000], then sum = 1*num != 0, since do while executes at least once
	int max = 1000/num;
	do{
		sum += i*num;
		i++;
	} while(i <= max);
	return sum;
}





//QUESTION 2
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){ // Determine which range does Q2_input fall into. Keep in mind the floating point number range. Assign the correct output to the result.

	int result;

	if (Q2_threshold == 0)
		result = -999;

	else if (Q2_threshold > 0){ //if threshold is positive
		if (Q2_input >= -2*Q2_threshold){
			if(Q2_input >= -1*Q2_threshold){
				if(Q2_input >= 0){
					if(Q2_input >= 1*Q2_threshold){
						if (Q2_input <= 2*Q2_threshold){
							result = 3;
						}
						else{result = -999;}
					}
					else{result = 2;}
				}
				else{result = 1;}
			}
			else{result = 0;}
		}
		else {result = -999;}
	}

	else {
		if (Q2_input <= -2*Q2_threshold){
			if(Q2_input <= -1*Q2_threshold){
				if(Q2_input <= 0){
					if(Q2_input <= 1*Q2_threshold){
						if (Q2_input >= 2*Q2_threshold){
							result = 3;
						}
						else{result = -999;}
					}
					else{result = 2;}
				}
				else{result = 1;}
			}
			else{result = 0;}
		}
		else {result = -999;}
	}

	return result;
}




//===============================================================================================
int Q3(int Q3_input, int perfect[]){

	//counts = amount of perfect nums
	//i = the current num checking if its a perfect num
	//j = the current num checking if its a factor of i, the possibly perfect num
	int counts = 0, sum, i, j;
	for (i = 1; i <= Q3_input; i++){
		sum = 0;
		for (j = 1; j < i; j++){
			if (i % j == 0){
				sum += j;
			}
		}
		if (sum==i){
			perfect[counts] = i;
			counts++;
		}
	}
	return counts;
}

//===============================================================================================
int Q4_Bubble(int array[], int size){ // This variable tracks the number of passes done on the array to sort the array.
	int passes = 0, prevPasses = 0, i;
	do {
		prevPasses = passes;
		for (i = 0; i < size - 1; i++){
			if (array[i] > array[i+1]){
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				if (passes == prevPasses){
					passes++;
				}
			}
		}
	} while (prevPasses != passes);
	passes++; //include last run through even tho no swaps made
	return passes; //return the number of passes used to complete the Bubble Sort
}