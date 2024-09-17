#include <stdio.h>

int main (void){

    //DYNAMIC MEMORY ALLOCATION

    //POINTER ARITHMETIC__________________________________________________________________________
    int a[8] = {0,1,2,3,5,7,8,0};
    int* aPtr = NULL;
    aPtr = a[2];

    //the following statements are all equivalent
    *(aPtr+3) = 10;
    a[2+3] = 10;
    a[5] = 10;

    //the following are all equivalent
    *++aPtr = 20;
    *(++aPtr) = 20;
    *(aPtr+1) = 20;
    a[2+1] = 20;
    a[3] = 20;

    //the following are all equivalent
    *--aPtr = 25;
    *(--aPtr) = 25;
    a[1] = 25;


    aPtr = a[6]; //ie 0x61FF20 = 6422304
    int* bPtr = a[2]; //ie 0x61FF10 = 6422288
    //the following are all equivalent
    int diffMemory;
    diffMemory = aPtr - bPtr;
    //diffMemory = (aPtrValue - bPtrValue) / sizeof(aPtr); //or sizzeof(bPtr), both are the same anyway
    diffMemory = (6422304 - 6422288) / 4; 
    diffMemory = 16 / 4;
    diffMemory = 4;

    //little endian - lowest byte of a word stored in the byte with the highest address


    //sizeof(); //FUNCTIONS
    float f[10];
    char s[] = "canada";
    char *p = "hello";

    sizeof(char);       //bytes to store a char variable
    sizeof(3.0+5.0);    //bytes for a double
    sizeof(int[4]);     //bytes for an array of 4 ints
    sizeof(int*);       //bytes for an int ptr
    sizeof(f);          //bytes for all float elements in f
    sizeof(s);          //bytes for all chars in s, including NULL
    sizeof(p);          //bytes for a char ptr



    //CONST QUALIFIER ON POINTERS_________________________________________________________________________
    const int* ptr1; //is a ptr to a constant int
    int* const ptr2; //is a constant ptr to an int
    const int* const ptr3; //is a constant ptr to a constant int



    //MORE POINTER STUFF__________________________________________________________________________
    int a[5];
    int* p = &a[1];
    a = p; //SYNTAX ERROR - address coressponding to the array name cannot be modified
    p = a; //no error

    //four possibilites to refer to element a[i]
            //1) a[i]    = array index (subscript) notation
            //2) p[i]    = po3inter index (subscript) notation/
            //3) *(p+i)  = pointer offset notation
            //4) *(a+i)  = pointer offset with array name

            //if attempting to step out of boundaries...the possible outcomes are...
                    //1) step into unused memory region (heap or stack) - by pure luck, nothing happens
                    //2) step into used memory region by other parts of program - program malfunctions
                    //3) step into defined memory region, either OS intervenes or program crashes


    //EXAMPLE
    int x[20];
    int i, *p;

    for (i=0; i<20; i++)
        scanf("%d",&a[i]);

    for (p=a; p<a+20; p++)
        printf("%d\t", *p);


    void foo1 (int array[], int size); //array name - implicit ptr
    void foo2 (int* array, int size);  //explicit ptr

    //DECLARATIONS 
    //ptr declaration and array declaration are only equivalent when declared in the input parameter list of a function

    //the following are NOT EQUIVALENT
    int a[3] = {0,1,2};
    int* p = {0,1,2}; //INVALID
                      //declaring pointing doesnt allocate memory



    //CHARACTER ARRAYS
    char str1[20];
    scanf("%s", str1); //contents can still be modified afterwards

    char str2[20] = "hello world!";
    str2[3] = 'L'; //can modifiy like this

    char* str3 = "hello world!"; //placed as a char array in read-only memory, str then points to the start
    str3 [3] = 'L'; //not allowed

    char* str4;
    scanf("%s", str4); //compilable but could lead to seg fault or data destruction
                       //because scanf will scan into unallocated memory section

    


    //INTRO TO DMA__________________________________________________________________________
    malloc(); //create
    calloc(); //create and 0init
    realloc(); //adjust size
    free(); //deallocates ie. destroy

    //allocates a consecutive portion of memory and returns a generic ptr to the first byte. like arrays
    //free() deallocates otherwise memory leak

    void *p; //generic ptr with no default type
             //contains memory address and ofc its pointed data
             //restricitions until type-casted:
                    //cannot be referenced
                    //ptr arithmetic is not defined on void*
    

    void* malloc (size_t n);
            //allocates n consecutve bytes of memory
            //returns void ptr to the first byte of this sector
            //the memory sector is uninitialised
            //if allocation request cannot be fulfilled, NULL ptr is returned
            if (p == NULL) return -1; //error checking


    void* calloc (size_t m, size_t n);
            //allocates memory for m number of objs, each with n bytes
            //returns a void ptr to the first byte of the sector
            //memory sector is initialised to 0
            //if allocation cannot be fulfilled, NULL ptr returned

    
    void* realloc(void* p, size_t new_size);
            //change the size of memeory sector pointed by p to new_size
            //returns a ptr to the new block or NULL if unfulfilled
            //exsiting contents in old blocks will remain unchanged
            //when downsizing, p will most likely be unchanged
            //when upsizing, p may change for a larger sector on the heap
                    //additional spaces will be uninitilised
                    //frees old blaock automatically if moved to new memory sector
            //UPSIZING
                    int *p, *q;
                    p = (int*)calloc(3,sizeof(int));
                    if (p == NULL) return -1;
                    //after some shenanigans
                    q = (int*)realloc(p,4*sizeof(int));
                    free(q);
                    free(p); //not necessary, already freed via realloc()
            //DOWNSIZING
                    int *p, *q;
                    p = (int*)calloc(3,sizeof(int));
                    if (p == NULL) return -1;
                    //after some shenanigans
                    q = (int*)realloc(p,2*sizeof(int));
                    free(q);
                    free(p); //not necessary, already freed via realloc()


    void* free (void* p);
            //deallocates memory sector pointed by p
            //p must be ptr to memory sector previously allocated by malloc(), calloc(), realloc()
            //no action taken if p is NULL


    

    //EXAMPLE
    //design a function to add 2 n-dimensional vectors
    //operand's array names are passed as functions parameters
            //option 1
                    //create sum array in the caller, and pass its name into the function
                    //sum vector array has storage duration of caller
                    //itll be allocated well before add() is called, but only used afterwards
                    //inefficient memory usage

            //option 2
                    //create sum array in the function, and return a ptr back to the caller
                    //sum vector array has storage duration completely under our control
                    //itll be allocated right before being used in add() and sustain until free() is called
                    //efficient memory usage

    
    //EXAMPLE DO
    int vec1[] = {1,2,3,5};
    int vec2[] = {5,3,2,1};
    int* p = NULL;
    p = add1 (vec1, vec2, 4);
    free(p);

    //EXAMPLE DONT
    int vec1[] = {1,2,3,5};
    int vec2[] = {5,3,2,1};
    int* p = NULL;
    p = add2 (vec1, vec2, 4);
    free(p);



    return 0;
}


int* add1(int v1[], int v2[], int size){
    int* sum = (int*)malloc(size*sizeof(int));
    int i;
    for (i=0; i<size; i++)
        sum[i] = v1[i] + v2[i];
    return sum;
}

int* add2(int v1[], int v2[], int size){
    //WONT WORK SINCE SUM ISNT STORED ON THE HEAP, SO EVERYTHING WILL BE LOST ONCE FUNCTION IS DONE
    int sum[size];
    int i;
    for (i=0; i<size; i++)
        sum[i] = v1[i] + v2[i];
    return &sum[0];
}