/* 
 * L12Ex6-String.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

// Demonstration of:
//  Everything learned in Topic 12
// Let's build a String container class

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
   MyString str1;
   MyString str2("Joe");
   MyString* str3 = new MyString("Ann");
   MyString* str4 = new MyString(str2);

   cout << str1.getString() << ", Len = " << str1.length() << endl;
   cout << str2.getString() << ", Len = " << str2.length() << endl;
   cout << str3->getString() << ", Len = " << str3->length() << endl;
   cout << str4->getString() << ", Len = " << str4->length() << endl;

   delete str3;
   delete str4;

   return 0;
}
