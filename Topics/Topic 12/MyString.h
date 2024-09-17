/*
 * MyString.h
 * 
 *  Created on: Sep 8, 2022
 *      Author: Scott Chen
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

class MyString
{
    private:
        char* pData;
        int nLength;

        // Helper Function
        int findLength(char* str);

    public:
        // Constructors
        MyString();
        MyString(char* s);
        MyString(const MyString &str);

        // Accessors (Getters)
        char* getString();
        int length();

        // Destructor
        ~MyString();
};


#endif /* MYSTRING_H_ */
