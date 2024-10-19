#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){
	
    char **word_list;        
    FILE* myFile;

    // Step 1:  Open file "input_filename" in ASCII read mode
    // Step 2:  Read the first line of the text file as an integer into nPtr
    //          This is the number of valid lines in the text file containing words to be sorted
    // Step 3:  Allocate an array of nPtr number of char pointer under word_list
    // Step 4:  Allocate an array of characters for each word under word_list; 
    //          Read each line from the input file and save it in the allocated array.  
    // Step 5:  Close the file handle
    // Step 6:  (for debugging purpose) Print out the contents in the string array
    //          This is for your own confirmation.  Remove this printing code before submission.
    
    
    myFile = fopen(input_filename, "r");

    char buffer [100];
    fscanf(myFile, "%d", &nPtr);

    word_list = (char**)malloc(*nPtr *sizeof(char*)); //must dereference nPtr to get the number of words

    int i,j;
    for (i = 0; i < *nPtr; i++) {
        if (fgets(buffer, sizeof(buffer), myFile) != NULL) { // Allocate memory for each word (including space for '\0' terminator)
            word_list[i] = (char *)malloc(sizeof(buffer) + 1);

            // Copy word, then remove \n
            int j = 0;
            while (buffer[j] != '\0' && buffer[j] != '\n') {
                word_list[i][j] = buffer[j];
                j++;
            }
            word_list[i][j] = '\0';  // Null-terminate the copied string
        }
    }
     
    fclose(myFile); 
    return word_list;
}

void swap(char **str1, char **str2) {    
    //swap the contents on each str
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void delete_wordlist(char **word_list, int size) {
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    /*THINK ABOUT WHY!!!*/

    int i;
    for (i=0; i < size; i++){
        free(word_list[i]);
    }
    free(word_list);
}

void sort_words_Bubble(char **words, int size) {   
	//write your implementation here
    // Hint: Use your own my_strcmpOrder to compare the ASCII size of the two strings, and use the returned result as the sorting reference.
    // Hint: Use swap() if string swapping is required

    int passes = 0, prevPasses = 0, i;
	do {
		prevPasses = passes;
		for (i = 0; i < size - 1; i++){
			if ((my_strcmpOrder(words[i],words[i+1])) == 1){
				swap(&words[i], &words[i+1]);

                passes++;
			}
		}
	} while (prevPasses != passes);
    
}

void sort_words_Selection(char **words, int size){
    // This implementation of string-sorting function using Selection Sort contains 2 semantic bugs
    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.
    // You will be tested again at the cross exam.
    // If you forgot how Selection Sort works, review Lab 2 document.

    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++){
        minIndex = i;

        for(j = i + 1; j < size-1; j++){
            if(my_strcmpOrder(words[minIndex], words[j]) == 1){
                minIndex = j;
            }                        
        }
       
        if(minIndex != i){
            swap(&words[i], &words[minIndex]);
        }

    }
    
}

