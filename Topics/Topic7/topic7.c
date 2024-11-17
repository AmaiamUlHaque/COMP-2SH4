

#include <stdio.h>

int main (void){

    //COMPUTER MEMORY STRUCTURE
    //- program - compiler machine code
    //- static variable - static and global variables. sub section of program memory
    //- stack/auto - non static local variables
    //- heap - dynamic memory allocation - creation and deletion of varibles on the heap

    //stack overflow - when stack/auto section becomes to big and overlaps with program section



    //& = reference operater - the address
    //%p = pointer conversion specificer
    //%x = hexadecimal conversion specificer. sometimes used in place of %p

    //can tell how many bits are strored via the difference between each address
    //array name is a constant pointer value

    //pointer has different variations
    //int, float, char, double (double precision float)
    int* ptr1; //both are correct
    int *ptr2;

    int *ptr3 = NULL, *ptr4 = NULL;
    int n = 0;
    //can also do
    int *nPtr1 = NULL, *nPtr2 = NULL, n = 0;

    //when initialising ptrs, they should be declared to NULL, otherwise itll have random garbage inside, 
    //and if dereferenced, it might access something you shouldnt and lead to seg fault or crashing


    //* = dereference operator - the value at the address
    int var = 3+5;
    int* ptr_var = &var;
    *ptr_var += 10; //the genuine value of var will be +10

    int n=3;
    printf("varible n has value %d stored %p\n", n, &n);

    int* ptr_n = &n;
    printf("address %p has value %d storied in it\n", ptr_n, *ptr_n); //*ptr_n is dereferncing (which is the value at the stored address)

    int m[3] = {101,102,103};
    printf("array name has value %d at address 0x%p\n", m, &m);
    printf("first array element has value %d at address 0x%p\n", m[0], &m[0]);
    printf("second array element has value %d at address 0x%p\n", m[1], &m[1]);
    printf("third array element has value %d at address 0x%p\n", m[2], &m[2]);



    //PASS BY REFERENCE
    //by default parameters passed into a function are pass by value. ie values are copied


    //example. swapping variables
    int a = 5;
    int b = 3;
    swap(&a,&b);


    //functions can only return one value at a time. but w/ ptrs, multiple genuine values can be returned
    int sum, diff;
    sum_diff(a,b, &sum, &diff);




    return 0;
}

swap (int* ptr1, int* ptr2){
    int* temp;
    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void sum_diff(int a, int b, int* sumPtr, int* diffPtr){
    *sumPtr = a+b;
    *diffPtr = a-b;
    //this way both the sum and difference are returned, instead of only one value being able to return
}