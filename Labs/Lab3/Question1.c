#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1) {
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	int i=0;
	 while (str1[i] != '\0'){
        i++;
    }
	return i;
}

int my_strcmp(const char * const str1, const char * const str2) {
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	// Criteria 1: Check their lenghts.  If not the same length, not equal
	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal
	// if passing the two criteria, strings equal

	int string1 = my_strlen(str1);
	int string2 = my_strlen(str2);
	int match = 1;

	if (string1 == string2){
		int i;
		for (i=0; i<string1; i++){
			if (str1[i] != str2[i]){
				match = 0;
				break;
			}
		}
	}
	else match=0;

	return match;
}


int my_strcmpOrder(const char * const str1, const char * const str2) {
	//compare_str alphabetically compares two strings.
	//If str2 is alphabetically smaller than str1 (comes before str1), the function returns a 1, 
	// else if str1 is smaller than str2, the function returns a 0.
	// if two strings are completely identical in order, return -1.
	
	int result;

	if (my_strcmp(str1, str2) == 1){ 
		return -1;
	}

	else {
		int i=0;
		do {
			if (str1[i] != str2[i]){
				if (str1[i] < str2[i]){
					return 0;
				}
				else {
					return 1;
				}
			}
			i++;
		} while (str1[i] != 0 || str2[i] != 0);
	}	
}


char* my_strcat(const char * const str1, const char * const str2){

	char *z = NULL; // this is the pointer holding the string to return
	int string1 = my_strlen(str1);
	int string2 = my_strlen(str2);
	int size = string1 + string2 + 1; //size of both strings plus 1 for the '\0'

	z = (char*)malloc(size*sizeof(char));

	int i;
	for (i=0; i<string1; i++){
		z[i] = str1[i];
	}
	for (i=0; i<string2; i++){
		z[i+string1] = str2[i];
	}
	z[size-1] = 0;

	return z;
	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT

	//free(z) should use, but not for this questions purposes, as mentioned in lab manual
}