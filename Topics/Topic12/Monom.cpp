/*
 * Monom.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

#include <iostream>

#include "Monom.h"

using namespace std;

// Implementation of Monom’s Initializer
// :: (scope operator) links member function to its class

Monom::Monom()  // Default Constructor (initializer)
{
    coeff = 0.0f;
    power = 0;
}

// Implementation of Monom’s Alternative Initializer
Monom::Monom( float coe, int pow )  // function overload
{
    coeff = coe;
    power = pow;
}


// Getters
float Monom::GetCoeff(){
    return coeff;
}

int Monom::GetPower(){
    return power;
}


// Setters
void Monom::SetCoeff( float coe ){
    coeff = coe;
}

void Monom::SetPower( int pow ){
    power = pow;
}


// Other external member functions
void Monom::print(){
    cout << coeff << "x^" << power << endl;
}

Monom Monom::Product( Monom op ){

    // Memory Inefficient (Why?)
	Monom temp = Monom();
    temp.SetCoeff( coeff * op.coeff );
    temp.SetPower( power + op.power );
    return temp;
}

Monom Monom::Quotient( Monom op ){

    // Memory Inefficient (Why?)
	Monom temp = Monom();
    temp.SetCoeff( coeff / op.coeff );
    temp.SetPower( power - op.power );
    return temp;
}
