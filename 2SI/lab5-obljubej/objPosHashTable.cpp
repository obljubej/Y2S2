#include <iostream>
#include "objPosHashTable.h"

// Provided Code for Model Code Integration
////////////////////////////////////////////////

// uncomment this line when integrating with model code
// #include "./Lab5-Model/inc/MacUILib.h"

using namespace std;

objPosHashTable::objPosHashTable()
{
    // create the hash table with default size (TABLE_SIZE)

    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)
    tableSize = TABLE_SIZE;
    myHashTable = new objPos[tableSize];
    for(int i = 0; i < tableSize; i++){
        myHashTable[i] = objPos(0, 0, '\0', 0, '\0');
    }
}

objPosHashTable::objPosHashTable(int size)
{
    // create the hash table with the custom size (size)

    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)
    tableSize = size;
    myHashTable = new objPos[tableSize];
    for(int i = 0; i < tableSize; i++){
        myHashTable[i] = objPos(0, 0, '\0', 0, '\0');
    }
}

objPosHashTable::~objPosHashTable()
{
    // remove the hash table
    delete[] myHashTable;
}

int objPosHashTable::calculateHashing(int prefix, int number) const
{
    // calculate the hash index using the prefix and number.

    // Formula: Add all digits of the number and the integer value of the ASCII prefix.

    // Ex. prefix = 'A'(65), number = 37
    //     return value = 6 + 5 + 3 + 7 = 21
    int hashValue = 0;
    int ASCII_VALUE = (int)prefix;

    while(ASCII_VALUE > 0){
        hashValue += ASCII_VALUE % 10;
        ASCII_VALUE /= 10;
    }
    while(number > 0){
        hashValue += number % 10;
        number /= 10;
    }
    hashValue = hashValue % tableSize;
    return hashValue;
}

double objPosHashTable::getLambda() const
{
    // calculate the load factor of the hash table
    int count = 0;
    for(int i = 0; i < tableSize; i++){
        if(myHashTable[i].getSym() != 0){
            count++;
        }
    }
    return (double)count/tableSize;
}

void objPosHashTable::printMe() const
{
    // Provided for verbose mode in Test.cpp
    // comment the entire for-loop out when integrating with the model code.
    for(int i = 0; i < tableSize; i++)
    {
        cout << "[" << i << "]  " << myHashTable[i].getPF() << myHashTable[i].getNum() << " " << myHashTable[i].getSym() << endl;     
    }



    // Provided Code for Model Code Integration
    ////////////////////////////////////////////////

    // uncomment the following lines when integrating with model code

    // MacUILib_printf("[ ");
    // for(int i = 0; i < TABLE_SIZE; i++)
    // {
    //     if(myHashTable[i].getSym() != 0)
    //         MacUILib_printf("%c%d ", myHashTable[i].getPF(), myHashTable[i].getNum());     
    // }
    // MacUILib_printf("] L=%.2f", getLambda());

    // You will also need to #include "MacUILib.h" when integrating with the model code.
}