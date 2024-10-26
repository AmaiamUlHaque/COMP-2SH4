
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>
using namespace std;

Matrix::Matrix() { // Default Constructor

	/* // This is a sample constructor with the default matrix size set to 3x3
	// Two key concepts here:
	//  1. in C++, use the keyword new for heap memory allocation calls
	//  2. When a C++ class has heap data members, allocate heap memory for them in the constructor
	//     THEREFORE, you may need to add a destructor to deallocate the memory.
	//     (You need to add it yourself!!) 
	*/

	rowsNum = 3;
	colsNum = 3;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++) {
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = 0;

}



Matrix::Matrix( int row, int col ) {// Additional Constructor

	if (row <= 0 ){
		row = 3;
	}
	if (col <= 0 ){
		col = 3;
	}

	rowsNum = row;
	colsNum = col;
	matrixData = new int*[row];


	for(int i = 0; i < row; i++) {
		matrixData[i] = new int[col];
	}

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			matrixData[i][j] = 0;

}



Matrix::Matrix(int row, int col, int** table) { // Additional Additional Constructor
	
	rowsNum = row;
	colsNum = col;
	matrixData = new int*[row];

	for(int i = 0; i < row; i++) {
		matrixData[i] = new int[col];
	}

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			matrixData[i][j] = table[i][j];
	
}



Matrix::~Matrix() { //Deconstructor

	for(int i = 0; i < rowsNum; i++) {
		delete [] matrixData[i];
	}

    delete[] matrixData;
}



Matrix::Matrix(const Matrix &sMatrix){ //Copy Constructor

    rowsNum = sMatrix.rowsNum;
    colsNum = sMatrix.colsNum;
    matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++) {
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = sMatrix.matrixData[i][j];

}



Matrix& Matrix::operator=(const Matrix &sMatrix){ //Copy Assignment Operator

	if (this != &sMatrix){ //just in case of self assignment
			
		this->rowsNum = sMatrix.rowsNum;
		this->colsNum = sMatrix.colsNum;

		for (int i = 0; i < rowsNum; i++) {
            for (int j = 0; j < colsNum; j++) {
                matrixData[i][j] = sMatrix.matrixData[i][j];
            }
        }
	}

	return *this;

}



int Matrix::getElement(int i, int j) { // Getter Method - get element at [i][j]

	if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum){
		throw std::out_of_range("Invalid indexes.");
	}

	else {
		return matrixData[i][j];
	}

}



bool Matrix::setElement(int x, int i, int j) { // Setter Method - set element at [i,j]

	// C++ Error Handling Method 2: Boolean Status Return
	// If the return value of a function is not used for data passing, you may deploy an alternative way
	// to handle the index-out-of-bound error.
	// Design Recommendation: unless communicated with your SW team, you should use Exception by default.

	if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum){
		return false;
		throw std::out_of_range("Invalid indexes.");
	}

	else {
		matrixData[i][j] = x;
		return true;
	}

}



int Matrix::getsizeofrows() { // Getter - get row size

	return rowsNum;

}



int Matrix::getsizeofcols() { // Getter - get column size
    
	return colsNum;

}



void Matrix::addTo( const Matrix m ) { // Member Function - add matrix m to this
	
	// Error Handling
	// Check dimension matching.  If failed, throw the following exception:
	//	throw std::invalid_argument("Invalid operation.");


	if (this->rowsNum != m.rowsNum || this->colsNum != m.colsNum){
		throw std::invalid_argument("Invalid operation.");
	}

	else {
		for (int i = 0; i < rowsNum; i++) {
            for (int j = 0; j < colsNum; j++) {
                matrixData[i][j] += m.matrixData[i][j];
            }
        }
	}

}



Matrix Matrix::subMatrix(int i, int j) { // Member Function - get upper-left sub matrix

	/*
	// Description of the functionality:
	//  The function accepts two params:
	//    i - the row-index of the lower-right corner of the sub matrix
	//    j - the col-index of the lower-right corner of the sub matrix
	//  Then, the function will return the submatrix from this matrix as such
	//	  The submatrix has the exact size that can hold all the elements from [0, 0] to [i, j]
	//    and its values are identical to the elements of this matrix from [0, 0] to [i, j]

	//  For example, given the following matrix
	//      1 2 3
	//  m = 4 5 6 
	//      7 8 9
	//  Then, m.subMatrix(1, 1) will return
	//   1 2
	//   4 5

	// Error Handling
	/////////////////////
	// If either i or j is out of the matrix index bound, you should follow the C++ error handling convention
	// by throwing an exception as described below 
	//		throw std::out_of_range("Submatrix not defined.");
	*/
	
	if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum){
		throw std::out_of_range("Submatrix not defined.");
	}

	else {

		Matrix submatrix(i+1,j+1,this->matrixData);

		return submatrix;

	}

}



string Matrix::toString() { //Member Function - covert to string

	// Member Function - String Conversion Method
	///////////////////////////////////////////////
	//
	// Most of the C++ classes contain a toString() method to allow its data members
	// to be presented in a string format, so that its contents can be displayed on the console screen
	// or other terminal interfaces for debugging / UI purposes.
	// 
	// This method requirexs the matrix to be output in the following string format:
	//           4 5 6
	// Given m = 1 2 3 , then the string output should be "4 5 6 \n1 2 3 \n7 8 9 \n"
	//           7 8 9  
	//
	// such that if cout << m.toString(); is executed, the output on the console screen will be:
	// 
	// 4_5_6_  (_ is space character just to illustrate where the whitespaces are expected) 
	// 1_2_3_
	// 7_8_9_
	//
	// You may use the C++ string library for string assembly purpose
	// Look up the C++ string library documentations to learn how to use it for your design purpose.
	// You may further use the to_string() function from the <iostream> library to help with converting
	// non-string data types to its string format.  Read documentations before using it!!

	string output;

	for (int i = 0; i < rowsNum; i++){
		for (int j = 0; j < colsNum; j++){
			output += to_string(matrixData[i][j]) + ' ';
		}
		output += '\n';
	}

	return output;
}



Matrix Matrix::copy() { //DEBUGGED

	// Member Function - Create a Copy of This Matrix (NOT a copy constructor)
	// The function is intended:
		// 1. Create an instance of a matrix of the same dimensions as itself
		// 2. Copy all the elements of itself to the new copied instance
		// 3. Return the instance of the Matrix
	// However, the implementation is faulty with two semantic bugs.
	// fix the code using VSCode IDE Debugger r or Debugging Message Printout using cout, and produce a simple debugging report
	
	
	Matrix copy = Matrix(rowsNum, colsNum);

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			copy.setElement(matrixData[i][j], i, j);

    return copy;
	
}

