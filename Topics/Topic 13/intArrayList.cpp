// Source Code here

#include "intArrayList.h"
#include <iostream>
using namespace std;


intArrayList:: intArrayList(){

    sizeList = 0;
    sizeArray = DEFAULT_SIZE;
    aList = new int [DEFAULT_SIZE];

    cout <<"default constructor called" <<endl;

}


intArrayList::intArrayList(const intArrayList &sList){

    sizeList = sList.sizeList;
    sizeArray = sList.sizeArray;
    //aList = sList.aList; // SHALLOW COPY - DONT DO THIS
    aList = new int [DEFAULT_SIZE];

    for (int i = 0; i<sizeList; i++){
        aList[i] = sList.aList[i];
    }

    cout <<"copy constructor called" <<endl;

}


intArrayList& intArrayList::operator=(const intArrayList &sList){

    if(this != &sList) {
        this->sizeArray = sList.sizeArray;
        this->sizeList = sList.sizeList;        
    }

    for (int i = 0; i< this->sizeList; i++){
        aList[i] = sList.aList[i];
    }

    cout <<"copy assignment operator  called" <<endl;  

}


intArrayList::~intArrayList() {

    delete[] aList;

    cout <<"destructor called" << endl;

}



//GETTERS

void intArrayList::printList(){

    if (sizeList == 0){
        cout << "list is empty" <<endl;
        return;
    }

    for (int i=0; i<sizeList; i++){
        cout << aList[i] << " ";
    }

    cout << endl;
}



int intArrayList::getSize(){

    printf(" ");    

}


void intArrayList::InsertTail (int element){

    aList[sizeList] = element;
    sizeList++;


}

void intArrayList::RemoveTail (){

    if (sizeList == 0){
        cout << "list is empty" << endl;
        return;
    }

    sizeList--; //lazy delete

}

void intArrayList::InsertHead (int element){

    if (sizeList == sizeArray){
        cout << "array is full" << endl;
        return;
    }

    for (int i=sizeList; i>0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = element;
    sizeList++;

}

void intArrayList::RemoveHead (){

    for (int i=0; i<sizeList-2; i++){
        aList[i] = aList[i+1];
    }

    sizeList--;

}

