/*
 * L12Ex1-MonomOOD.cpp
 *
 *  Created on: Sep 12, 2022
 *      Author: Scott Chen
 */

// C++
#include <iostream>
#include "Monom.h"

using namespace std;

// This is the demonstration of C++'s syntax features to enforce OOD design
//  Much more structured than C

// Main function
int main()
{
	// Notice that throughout this program, Monom behaves very much like an Object

	// Declare and Test the Initializer member function
	// These will invoke the Alternative Monom Constructor
	Monom mono1 = {0.3, 4};
	Monom mono2 = Monom(-2.3, 10);

	// These will invoke the default Monom Constructor
	Monom mono3; // Product Result
	Monom mono4; // Quotient Result

	// Test the Getter Functions
	cout << "Mono1 has the coefficient of " << mono1.GetCoeff() << " and power of " << mono1.GetPower() << endl;
	cout << "Mono2 has the coefficient of " << mono2.GetCoeff() << " and power of " << mono2.GetPower() << endl;
	cout << "Mono3 has the coefficient of " << mono3.GetCoeff() << " and power of " << mono3.GetPower() << endl;
	cout << "Mono4 has the coefficient of " << mono4.GetCoeff() << " and power of " << mono4.GetPower() << endl;

	// Test the (Inefficient) Product function
	mono3 = mono1.Product(mono2);
	// Test the (Inefficient) Quotient function
	mono4 = mono1.Quotient(mono2);

	// Test the Print Function
	mono1.print();
	mono2.print();
	mono3.print();
	mono4.print();

	// Test the Getter Functions Again
	cout << "Mono1 has the coefficient of " << mono1.GetCoeff() << " and power of " << mono1.GetPower() << endl;
	cout << "Mono2 has the coefficient of " << mono2.GetCoeff() << " and power of " << mono2.GetPower() << endl;
	cout << "Mono3 has the coefficient of " << mono3.GetCoeff() << " and power of " << mono3.GetPower() << endl;
	cout << "Mono4 has the coefficient of " << mono4.GetCoeff() << " and power of " << mono4.GetPower() << endl;

    // Demo of scope protection
	//  the following statements will work in C (because C has no scope protection)
	//  but will fail in C++ compilation thanks to OOD syntax support
	//mono3.coeff = 62.1;    // accessing private members, not allowed!!
	//mono4.power = 12;      // accessing private members, not allowed!!

	//mono3.SetCoeff(62.1);  // accessing private member function, not allowed!!
	//mono4.SetPower(12);    // accessing private member function, not allowed!!

	// with public / private scope control, accesses to the private members will have to be done
	// through fully-implemented and validated methods ONLY!
	//  ex. Assignment (=), Constructors (Monom()...)
	// Benefit - great implementation protection, no accidental misuse of object

	return 0;
}
