#include <stdio.h>

int main (void){

    //ARRAY OF POINTERS - DOUBLE POINTERS
        

    //DMA FOR MULTIDIMENSIONAL ARRAYS

                //2D arrays on stack
                //compiler does the 1D to 2D transformation for us
                //compiler translates a[][] to the a[] for us

                //2D array on heap
                //malloc always gets you 1D array
                //ie. want a 3x3 2D array, you get 1x9 1D array on the heap
                //we only get a single ptr to the head of the array
                //programmer has to do everything  manually

                //MUST DEALLOCATE IN REVERSE ORDER

    

    //METHOD 1 - only ptr - index calculated manually

            //initialise
            int m=3, n=3;
            char* ptr;
            ptr = (char*)malloc(m*n*sizeof(char));

            //math + ptr
            *(ptr + 2*n + 0) = 'a'; //ptr[2][0] = 'a'
            ptr[ 1*n + 1] = 'c'; //ptr[1][1] = 'c'

            //deallocation
            free(ptr);
            ptr=NULL;



    //METHOD 2 - ptr + row ptrs

            //initialise
            int m=3, n=3;
            char* ptr;
            ptr = (char*)malloc(m*n*sizeof(char));

            //make our own row ptrs
            char* ptrR0 = ptr + 0*n; //for row 0
            char* ptrR1 = ptr + 1*n; //for row 1
            char* ptrR2 = ptr + 2*n; //for row 2

            //to access ptr[i][j]
            //ptrRi[j];
            //*(ptrRi+j)


            //deallocation
            free(ptr);
            ptr = NULL;
            ptrR0 = NULL;
            ptrR1 = NULL;
            ptrR2 = NULL;
    

    //METHOD 3 - ptr + row arrays

            //initialise
            int m=3, n=3;
            char* ptr;
            ptr = (char*)malloc(m*n*sizeof(char));


            //save row ptrs into array
            char* RowPtrs[3] = {NULL, NULL, NULL};
            RowPtrs[0] = ptr + 0*n; //for row 0
            RowPtrs[1] = ptr + 1*n; //for row 1
            RowPtrs[2] = ptr + 2*n; //for row 2


            //to access ptr[i][j]
            *(RowPtrs[2]+0) = 'a'; //ptr[2][0] = 'a'
            RowPtrs[1][1] = 'c';


            //deallocation
            free(RowPtrs);
            free(ptr);
            ptr = NULL;



    //METHOD 4?ISH - automated sorta

            //initialise
            int m,n,i;
            float** dptr;
            printf("Provide size (m,n): ");
            scanf("%d , %d", &m, &n);

            dptr = (float**)malloc(m*sizeof(float*));
            for(i=0; i<m; i++)
                dptr[i] = (float*) malloc(n*sizeof(float));
            
            //to access
            dptr[1][1] = 10.5;

            //deallocate
            free(dptr);
            dptr = NULL;



    //MEMORY DEBUGGING
    //as soon as malloc or calloc, immediately write the free() part
    //use Memory Profiler to check for any memory leaks
    //memory profiler for windows - "drmemory ./programName.exe"




    //DOUBLE POINTERS

    int m=3, n=3;
    char* ptr;
    ptr = (char*)malloc(m*n*sizeof(char));

    char* RowPtrs[3] = {NULL, NULL, NULL};
    RowPtrs[0] = ptr + 0*n; //for row 0
    RowPtrs[1] = ptr + 1*n; //for row 1
    RowPtrs[2] = ptr + 2*n; //for row 2
    //deallocation
    free(RowPtrs);
    free(ptr);
    ptr = NULL;

    /*
    what is RowPtrs???
    = name of char ptr array
    = starting address of char ptr array
    = constant ptr to char ptr array
    = constant ptr to ptr
    = constant double ptr
    */


   //example
   int a = 100;
   int* p = &a;
   int** pp = p;
   //**pp = *(*pp) = = *(p) = a = 100
   **pp = 100;


   //ADVANTAGES OF MULTI DIMENSIONAL ARRAYS

        //DISTRIBUTED ARRAYS
                //each row can occupy seperated memeory sector
                //no chunky memeory

        //ODD SHAPED ARRAYS
                //efficient memory usage
                //support "arrays of strings"

                int a[] = {1,2};
                int b[] = {3,4,5,6};
                int c[] = {3,4,5};

                //simply
                int* pp[3] = {a,b,c};
                //this works too
                pp[0] = a;
                pp[1] = b;
                pp[2] = c;

                //access
                //a[j] == pp[0][j] == *(pp[0] + j)
                //b[j] == pp[1][j] == *(pp[1] + j)
                //c[j] == pp[2][j] == *(pp[2] + j)
                //**pp == *(*pp) == *(pp[0]) == a[0] == 1

                //limitations
                        //out of bound access possible and easy to do
                        //cannot have nested initialistion list
                        int* ppp[3] = {{1,2}, {3,4,5}, {7,8,9}}; //SYNTAX ERROR - pp can only hold 3 ptr values
                

                //ARRAY OF STRINGS
                char* strArray[] = {"mcMaster", "2SH4", "2SI3", "1D04"};
                //can swap strings by swapping the ptrs to the strings


   //DMA FOR MULTIDIMENSIONAL ARRAYS












        return 0;

}