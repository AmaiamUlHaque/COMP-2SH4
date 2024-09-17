/*
 * L16Ex4d-TimeDynamicPBR.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: Dr. Scott Chen
 * Modified by: Dr. Shahrukh Athar on June 18, 2024
 */

// This sample code extends from the Grand Example in Topic 14 (C++ Inheritance).
// (Time.h and ExtTime.h)

#include <iostream>
using namespace std;

#include "Time.h"
#include "ExtTime.h"

// To deploy polymorphism, need to use pass-by-reference
// (or use pass-by-pointer)
void print(Time &t)
{
   cout << "Time is: ";
   t.Write();  // This is our intended polymorphic call
                // Since we are using pass-by-reference, dot operator . is used
   cout << endl;
}

// ** Furthermore, Write() is declared virtual in Time class
//    and the destructors of Time and ExtTime classes are declared virtual too

// Client Code
int main()
{
   Time t1(8, 30, 0);
   ExtTime t2(10, 45, 0, CST);

   // With virtual function + pass-by-reference (or pass-by-pointer), polymorphism will work
   // Thanks to dynamic binding.
   print(t1);
   print(t2);

   return 0;
}
