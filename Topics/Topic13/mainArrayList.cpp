#include <iostream>
#include "intArrayList.h"

using namespace std;

int main()
{
    // 1. Test Constructor, Destructor
    intArrayList myList1; //default constructor
    intArrayList* myList2 = new intArrayList();
    intArrayList myList3 = myList1; //copy assignment constructor called


    // 2. Test print and assignment


    // 3. Test add to head and tail
    
    myList1.InsertTail(2);
    myList1.InsertTail(3);
    myList1.InsertTail(4);
    myList1.printList();

    // 4. Test getHead, getTail, getElement

    
    // 5. Test remove head and tail

    // 6. Test copy assignment operator
    myList3 = myList1; //copy assignment operator


    delete myList2; //not delete[] myList2; instead will call its detructor first
    return 0;
}
