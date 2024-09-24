#include "objPosDoubleHashing.h"
//#include "MacUILib.h"

#include <iostream>
using namespace std;

objPosDoubleHashing::objPosDoubleHashing()
{
    // do you need anything here?     
}

objPosDoubleHashing::objPosDoubleHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here?
}

objPosDoubleHashing::~objPosDoubleHashing()
{
    // do you need anything here? 
}

int objPosDoubleHashing::calculateSecondaryHashing(int input) const
{
    // Secondary Hashing Function
    // Formula : sum of all digits of the first hashing index mod 5.
    // Ex. Hashing Index = 36, then Secondary Hashing Index = (3 + 6) % 5 = 4

    int key = 0;
    while (input > 0){
        key += input % 10;
        input /= 10;
    }
    return 5 - (key % 5);
}

bool objPosDoubleHashing::insert(const objPos &thisPos)
{
    // Insert thisPos into the Hash Table (if not already inserted) using Double Hashing

    // When inserting, using Symbol as a way to check if the table entry is occupied or free
    //    Symbol = 0 (FREE),   Symbol = 'v' (Occupied)

    int key = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int key2 = calculateSecondaryHashing(key);

    for (int i = 0; i < MAX_PROBING_COUNT; i++){
        int index = (key+i*key2)%tableSize; //double probing
        if (myHashTable[index].getSym() == 0){
            myHashTable[index] = thisPos;
            myHashTable[index].setSym('v');
            return true;
        }
        else if (myHashTable[index].getSym() == 'v' && 
        myHashTable[index].getPF() == thisPos.getPF() && 
        myHashTable[index].getNum() == thisPos.getNum()){
            return false;
        }
    }
    return false;
}

bool objPosDoubleHashing::remove(const objPos &thisPos)
{
    // Remove thisPos from the Hash Table using Double Hashing

    // If found in the table, apply lazy deletion by setting Symbol = 0 (free), and return true
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.    

    int key = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int key2 = calculateSecondaryHashing(key);

    for (int i = 0; i<MAX_PROBING_COUNT; i++){
        int index = (key + i*key2) % tableSize;

        if (myHashTable[index].getSym()==0 && 
        myHashTable[index].getPF() == 0 && 
        myHashTable[index].getNum() == 0){
            return false;
        }
        if (myHashTable[index].getSym() == 'v' && 
        myHashTable[index].getPF() == thisPos.getPF() && 
        myHashTable[index].getNum() == thisPos.getNum()){
            myHashTable[index].setSym('\0');
            return true;
        }
    }
    return false;
}

bool objPosDoubleHashing::isInTable(const objPos &thisPos) const
{
    // Check if thisPos is in the Hash Table using Double Hashing

    // If found in the table, return true
        // Remember, finding the match is not enough.  The entry has to be VALID (symbol = 'v').
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.    

    int key = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int key2 = calculateSecondaryHashing(key);

    for (int i= 0; i< MAX_PROBING_COUNT; i++){
        int index = (key + i*key2)%tableSize;
        if(myHashTable[index].getSym() == 0 && 
        myHashTable[index].getPF() == 0 && 
        myHashTable[index].getNum() == 0){
            return false;
        }
        if (myHashTable[index].getSym()=='v'&& 
        myHashTable[index].getPF() == thisPos.getPF() && 
        myHashTable[index].getNum() == thisPos.getNum()){
            return true;
        }
    }
    return false;
}