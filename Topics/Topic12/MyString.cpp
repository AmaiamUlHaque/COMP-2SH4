/*
 * MyString.cpp
 *
 *  Created on: Sep 8, 2022 
 *      Author: Scott Chen
 */

#include "MyString.h"
#include <cstring>  // for strcpy() and strlen()

using namespace std;

// Our own string length calculator
// ** Private Helper Function
int MyString::findLength(char* str)
{
    int cnt;
    for(cnt = 0; str[cnt] != '\0'; cnt++);
    return cnt;
}


// Default Constructor
MyString::MyString()
{
    pData = new char[1];
    *pData = '\0';
    nLength = 0;
}

// Copy Constructor - with Deep Copy
MyString::MyString(const MyString &str)
{
    int n = str.nLength;
    pData = new char[n + 1];
    nLength = n;
    strcpy(pData, str.pData);
}

// Extra Constructor
MyString::MyString(char* s)
{
    nLength = findLength(s);
    pData = new char[nLength + 1];
    strcpy(pData, s);
}


// String Getter
char* MyString::getString()
{
   return pData;
}

// Length Getter
int MyString::length()
{
   return nLength;
}


// Destructor
MyString::~MyString()
{
    delete[] pData;
}

