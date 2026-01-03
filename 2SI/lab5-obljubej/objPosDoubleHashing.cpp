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
    int primaryHashIndex = 0;

    while(input > 0){
        primaryHashIndex += input % 10;
        input /= 10;
    }

    return 5 - (primaryHashIndex % 5);
}

bool objPosDoubleHashing::insert(const objPos &thisPos)
{
    // Insert thisPos into the Hash Table (if not already inserted) using Double Hashing

    // When inserting, using Symbol as a way to check if the table entry is occupied or free
    //    Symbol = 0 (FREE),   Symbol = 'v' (Occupied)
    int primaryIndex = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int secondaryIndex = calculateSecondaryHashing(primaryIndex);

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int index = (primaryIndex + i * secondaryIndex) % tableSize;
        if(myHashTable[index].getSym() == 0){
            myHashTable[index] = thisPos;
            myHashTable[index].setSym('v');
            return true;
        }
        if((myHashTable[index].getNum() == thisPos.getNum() &&
            myHashTable[index].getPF() == thisPos.getPF()) &&
            myHashTable[index].getSym() == 'v'){
                return false;
            }
    }
}

bool objPosDoubleHashing::remove(const objPos &thisPos)
{
    // Remove thisPos from the Hash Table using Double Hashing

    // If found in the table, apply lazy deletion by setting Symbol = 0 (free), and return true
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.  
    int primaryIndex = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int secondaryIndex = calculateSecondaryHashing(primaryIndex);

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int index = (primaryIndex + i * secondaryIndex) % tableSize;

        if(myHashTable[index].getSym() == 'v'){
            if(myHashTable[index].getPF() == thisPos.getPF() && myHashTable[index].getNum() == thisPos.getNum()){
                myHashTable[index].setSym(0);
                return true;
            }
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
    int primaryIndex = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int secondaryIndex = calculateSecondaryHashing(primaryIndex);

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int index = (primaryIndex + i * secondaryIndex) % tableSize;

        if(myHashTable[index].getSym() == 'v'){
            if(myHashTable[index].getPF() == thisPos.getPF() && myHashTable[index].getNum() == thisPos.getNum()){
                return true;
            }
        }
    }
}