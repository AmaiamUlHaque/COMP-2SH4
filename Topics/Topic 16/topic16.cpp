#include <iostream>

using namespace std;

int main() {

    //TOPIC 16 NOTES - POLYMORPHISM

    //PLV 16.1

        //abstract method - defined/prototype but no implementation
            //UML diagram - italicised


        //format of C library template thingy:
            /*
            #include "BaseClass.h"
            typedef BaseClass SubClass;

            void InitSubClass (SubClass* obj, (other parameters))

            whatever else stuff yu want            
            */
            //BUT COMPILATION ERROR IN C DUE TO REDEFINITION
            //NO OVVERIDE WHATSOEVER
            //C IS VERY PICKY WITH NAMESPACE CONTAMINATION
            //C is statically bound - ie. determined at time of compilation
            //C++ has way to be dynamically bound - ie. determined during runtime

    //PLV 16.2

        //basically its hella helpful for largescale stuff
            //eg. player swings and deals AOE dmg, and theres a bunch of enemies, 
            //    you only need to call the parent class Enemy and call its abstract method.
            //    this way, its only a line of code instead of specifiying the dmg for each and every single type of enemy

    
    //16.0 - OOD Polymorphism

        // DYNAMIC BINDING
            
            // NEED TO HAVE 'VIRTUAL' KEYWORD & PASS BY REF/PTR, otherwise itll be static bound

                //virtual needed infront of base class' function that you want to be polymorphed
                //base class' function must use pass by ref/ptr parameters --> even if its empty
                    // use arrow/ptr operator to refer to function instead of dot operator
                    // if function input pass by ref : obj &x , use .
                    // if function input pass by ptr : obj* x , use ->

            //during compilation, the complier throws in additional class-differentiating and decision making codes
            // to allow program to decide which member function to use on the fly

            //if a base class has a virtual function, the destructor must also be made virtual too
            
            //if derived class doesnt override virtual function, the base class' virtual one will be used

        //PURE VITRUAL
            //VIRTUAL STUFF AND THEN = 0 

        

            

    

    









}