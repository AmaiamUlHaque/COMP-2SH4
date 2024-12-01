// Let's define the array list class here

// Goal 1 - Mandatory Special Member Functions

// Goal 2 - Learn about Object Packaging


#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H

#define DEFAULT_SIZE 50

class intArrayList{

    private: 
        int* aList;
        int sizeList;
        int sizeArray;

    public: 
        intArrayList(); //default constructor (1/4)    
        intArrayList(const intArrayList &sList); //copy constructor (2/4)
        intArrayList& operator=(const intArrayList &sList); //assignment operator
        ~intArrayList(); //destrcutor (4/4)


    //getters
    void printList();
    int getSize();
    
    void InsertTail(int element);
    void RemoveTail();
    void InsertHead(int element);
    void RemoveHead();
    


};







#endif
