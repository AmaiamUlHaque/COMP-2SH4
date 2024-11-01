//TOPIC 2



//expression evaluates to a result. eg, function call
//statement is assigned to something. eg. if a function is returned and assigned to a variable

//STRUCTURE
//declare, initialise, execute

//FUNCTIONS
//for reusability(standard libraries and functions developed by others), modularity (easier design and mainteniance)
//function must be defined before main
//but only WIP functions should be above main (industry standard)
//so only function prototype goes before main

//FUNCTION ENCAPSULATION - the code inside the function ish
//FUNCTION PROTOTYPE - declaration, not defined. parameter list can have expected datatypes and variable name or just data type
//return_value_type function_name (parameter_list);
//parameter_list doesnt need variable names but needs the data types
int max(int x, int y); //w/ data types and var names
int max(int, int);
//FUNCTION DEFINITION - definition / implementation / the entire thingy
int max (int x, int y){
    int bigger = y;
    if (x > y)
        bigger = x;
    return bigger;
}
//FUNCTION INVOCATION
//PASS BY VALUE - values of arguments are COPIED to the respective parameters (only local copies are modified)



//C COMPILIATION PROCESS
// .c --> .c --> .s --> .o --> .exe
//1. editor - program created in IDE and stored on disk
//2. preprocessor - processes code and stores on disk (manipulates as directed: #include, #define, macros)
//3. compiler - creates object code/assembly and stores on disk
//4. linker - links object code/assembly w/ libraries and stores the .exe on the disk
//5. loader --> disk --> cpu

// CONST QUALIFIER
//variable that cant be changed after initialised w/ const keyword
const int constant = 55; //changing afterwards, will give syntax error
//ensure no accidently changing value

// STORAGE DURATION
// - c is efficiency minded
// - auto storage - all non global variables are automattically deallocated at the end of their scope
// - static storage - for global variables and functions to be stored thru out entire program
static int number; //automatically initiallised to 0
//can be for local vars too. ensures it retains its value thru out multiple function calls
//static != global



//MODULES
//functions defined in different source files can call each other
//to call func B in source B from source A's func A, include prototype B where func A is implemented

// library = header + source file
// HEADER FILE (.h) - contains function prototypes
// SOURCE FILE (.c) - contains function implementations
// - if standard header = <>, if you made = ""
#include <stdio.h>  //standard = <>
#include "mymath.h" //self made = ""
// - must compile source file then main file.  eg. gcc ./mymath.c ./main.c -o main
// - both must have the same names and in the same folder as the main program



//SCOPE OF VARIABLES

//LOCAL
//defined inside functions
//input parameters of functions
//can only be accessed within the function
//get destroyed at the end of the function

//GLOBAL
//defined outside of the functions --> top of source file or in header file
//exists as long as the program does

//SCOPE RULES
//FILE SCOPE - global vars and funcs
// BLOCK SCOPE - vars defined inside code block. eg. local vars
// FUNCTION SCOPE - labels (like case labels in 'switch' statement)
// FUNCTION PROTOTYPE SCOPE - identifiers in the parameter list of the prototype

//GLOBAL VARIABLE LINKAGE
//INTERNAL LINKAGE - global vars with 'static' in file A cant be referenced outside of file A
//EXTERNAL LINKAGE - global var 'g' defined in file A can be referenced from file B, if 'g' is declared in B w/ 'extern specificier

