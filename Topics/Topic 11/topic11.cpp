
//PLV 11.1 - SIMILARITIES BETWEEN C AND C++
//    11.0 - INTRO TO C++


// C89 Style C
#include <stdio.h>
#include<math.h>

int main (void) { //WORKS IN C++ COMPILER, EVEN THO ITS C

    printf("hello world\n");
    return 0;
}

int main2 (void) { 

    double x = 0.0;
    printf("enter x: ");
    scanf("%lf", &x);

    if (x>= 0){
        printf("Sqrt(%f) = %f\n", x, sqrt(x));
    }
    else {
        printf("cannot compute\n");
    }

    return 0;
}


// C++
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    std::cout << "hello world!\n"; //std is a library namespace (name of function collection)
    return 0;
}

int main2 () {

    double x {0.0};
    std::cout << "enter x: ";
    std::cin >> x;

    if (x>=0){
        std::cout << "Sqrt(" << x << ") = " << std::sqrt(x) << std::endl; //std::endl == printf("\n")
    }
    else {
        std::cout << "cannot compute" << std::endl;
    }

    return 0;
}

int main3 () {

    double x {0.0};
    cout << "enter x: ";
    cin >> x;

    if (x>=0){
        cout << "Sqrt(" << x << ") = " << sqrt(x) << endl; //std::endl == printf("\n")
    }
    else {
        cout << "cannot compute" << std::endl;
    }

    return 0;
}

int mainn () {

    //COMPILE COMMAND
    //  C:    gcc Demo.c -o Demo
    //  C++:  g++ Demo.cpp -o Demo

    //C++?
    /*  
        - proceural - identical
        - object orientied - deploys classes. has encapsulation, inheritance, polymorphism
        - idk but apparantly generic and STL = standard template library
        - can compile c programs usually
        - has a cleaner way to pass vy reference
        - stronger typed
        - immutability
        - extensive abstract mechanism
    */



    // NAMESPACE REPETITION
        //too much referencing the std library? define "using namespace std" at the top
        //before: std::cout << x;
        //after: cout << x;

    //PRIMITIVE VARIABLES
        //c++ has 'bool' 
        int x = 1;
        int y = 3;
        bool a = x > y; // holds value of 0 = false
        bool b = y > x; //holds value of 1 = true

    //BASIC OPERATORS
        //C operator precedence is the same 
        //there is instream and outstream
            //STREAM OPERATOR

            //STREAM INSERTION OPERATOR 
                // cout <<
                // used to send data to the standard output stream (usually the console) via the cout object
                // cout = standard output stream


            //STREAM EXTRACTION OPERATOR
                // cin >>
                // used to read data from the standard input stream (usually the keyboard) into variables via the cin object
                // cin = standard input stream

    //SELECTION and ITERATION
        //identical to C

    //FUNCTIONS
        //identical to C except C++ allows funtion overloading
            //FUNCTION OVERLOADING
                //functions can have same name 
                //BUT with different input/return types
                //reduces namespace contamination
                //invoker doesnt need to manage data types
                //examples provided below
    

    //C++ PASS BY REFERENCE

        //PASS BY VALUE
            //same as C

        //PASS BY POINTER
            //makes copies of memory addresses 
            //basically pass by value but w/ the addresses to modify genuine values
            //may be difficult for multi-level ptrs
            //should make ptr 'const' otherwise the address can be modified --> ie. lost info

            //example
            int c = 5;
            int d = 6;
            swap1(&c,&d);
        
        //PASS BY REFERENCE
            //more intuitive and secure way to allow direct access to genuine values
            //for input parameters, append address operator '&'
            //allows complier to have two variables that refer to the same memory location
            //references are immutable - no accidental destroying ptr address
            //less stack memory consumed
            //slightly faster execution time, however a bit more overhead on compiler
            
            //example
            int e = 7;
            int f = 9;
            swap2(e,f); //note that inside the function, the paramters are treated as ints and not ptrs

            //example
            int num = 14, den = 4, rem = 0;
            int quo = divide(num, den, rem);
            cout << quo << " * " << den << " + " << rem << " = " << num << endl;





}

//function overloading examples

    //OVERLOAD WORKING

        //# OF PARAMETERS
        //the function add is overloaded with different number parameters
        int add(int a, int b) {
            return a + b;
        }
        float add(float a, float b) {
            return a + b;
        }
        int add(int a, int b, int c) {
            return a + b + c;
        }

        //TYPES OF PARAMTERS
        //print is overloaded with different types of parameters
        void print(int i) {
        cout << "Integer: " << i << endl;
        }
        void print(string s) {
            cout << "String: " << s << endl;
        }

        //DEFAULT PARAMTERS
        //if display(5) --> prints 15
        //if display(5,3) --> prints 8
        void display(int a, int b = 10) {
        cout << a + b << endl;
        }  


    //OVERLOAD FAIL
        
        //AMBIGIOUS OVERLOADING
        //func(3) can be interperated as int or float or double
        void func(int a) { }
        void func(float a) { }
        void func(double a) { }

        //OVERLOADING VIA RETURN TYPE ALONE
        int getValue() { return 10; }
        //double getValue() { return 10.5; }  //causes a syntax error



void swap1 (int* ptr1, int* ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


void swap2 (int& x, int& y){ //note that the variables are treated as ints and not ptrs
    int temp = x;
    x = y;
    y = temp;
}

int divide (int numerator, int denominator, int& remainder){
    remainder = numerator % denominator;
    return numerator / denominator;
}
