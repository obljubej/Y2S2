#include "objPosLinearHashing.h"

#include <iostream>
using namespace std;

objPosLinearHashing::objPosLinearHashing()
{
    // do you need anything here?
}

objPosLinearHashing::objPosLinearHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here?
}

objPosLinearHashing::~objPosLinearHashing()
{
    // do you need anything here?     
}

bool objPosLinearHashing::insert(const objPos &thisPos)
{
    // Insert thisPos into the Hash Table (if not already inserted) using Linear Probing

    // When inserting, using Symbol as a way to check if the table entry is occupied or free
    //    Symbol = 0 (FREE),   Symbol = 'v' (Occupied)

    // If thisPos is already in the table, return false
    int index = calculateHashing(thisPos.getPF(), thisPos.getNum());

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int probeIndex = (index + i)%tableSize;
        if(myHashTable[probeIndex].getSym() == 0){
            myHashTable[probeIndex] = thisPos;
            myHashTable[probeIndex].setSym('v');
            return true;
        }
        if((myHashTable[probeIndex].getNum()==thisPos.getNum() &&
            myHashTable[probeIndex].getPF()==thisPos.getPF()) &&
            myHashTable[probeIndex].getSym() == 'v'){
                return false;
            }
    }
}

bool objPosLinearHashing::remove(const objPos &thisPos)
{
    // Remove thisPos from the Hash Table using Linear Probing

    // If found in the table, apply lazy deletion by setting Symbol = 0 (free), and return true
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.    
    int index = calculateHashing(thisPos.getPF(), thisPos.getNum());

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int probeIndex = (index + i) % tableSize;

        if(myHashTable[probeIndex].getSym() == 'v'){
            if(myHashTable[probeIndex].getPF() == thisPos.getPF() && myHashTable[probeIndex].getNum() == thisPos.getNum()){
                myHashTable[probeIndex].setSym(0);
                return true;
            }
        }
    }
    return false;
}

bool objPosLinearHashing::isInTable(const objPos &thisPos) const
{
    // Check if thisPos is in the Hash Table using Linear Probing

    // If found in the table, return true
        // Remember, finding the match is not enough.  The entry has to be VALID (symbol = 'v').
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.   
    int index = calculateHashing(thisPos.getPF(), thisPos.getNum());

    for(int i = 0; i < MAX_PROBING_COUNT; i++){
        int probeIndex = (index + i) % tableSize;

        if(myHashTable[probeIndex].getSym() == 'v'){
            if(myHashTable[probeIndex].getPF() == thisPos.getPF() && myHashTable[probeIndex].getNum() == thisPos.getNum()){
                return true;
            }
        }
    }
}