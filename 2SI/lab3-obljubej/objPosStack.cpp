#include "objPosStack.h"
#include "objPosSHLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      objPosList* myList
//      
//  This is the polymorphic list pointer to the underlying List data structure to
//   support all Stack functionalities
//
//  You should use the provided objPosSHLinkedList as your main design param (Singly with Header)


objPosStack::objPosStack()
{
    // Constructor   
    myList = new objPosSHLinkedList(); 
}


objPosStack::~objPosStack()
{
    // Destructor
    delete myList;
}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    srand(time(NULL));
    generateObjects(size);
    sortByTenScoreBS();   // bubble sort
}




// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
    
    // 1. Generate Prefix A-Z and a-z.  Alphabetic characters only.
    // 2. Generate Number [0, 99]
    // 3. Leave Symbol as *
    // Push every randomly generately objPos into the Stack.
    char prefix;
    int number;
    char symbol = '*';
    objPos temp;
    for (int i = 0; i < count; i++){
        if (rand() % 2 == 0){
            prefix = rand() % 26 + 'A';
        }
        else{
            prefix = rand() % 26 + 'a';
        }
        number = rand() % 100;
        temp.setPF(prefix);
        temp.setNum(number);
        temp.setSym(symbol);
        push(temp);
    }
}


// private helper function
void objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE or SELECTION SORT to sort all the objPos instances in the Stack in ascending order using the doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion, removal, getter, and setter methods from the objPosSHLinkedList interface
    //  to complete the sorting operations.
    objPos temp;
    objPos temp2;
    int swap = 1;
    int size = myList->getSize();
    do{
        swap = 0;
        for (int i = 0; i < size - 1; i++){
            temp = myList->get(i);
            temp2 = myList->get(i + 1);

            //check and swap
            if (temp.getNum() / 10 > temp2.getNum() / 10){
                myList->set(temp2, i);
                myList->set(temp, i + 1);
                swap = 1;
            }
        }
    } while (swap);
}




void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.
    objPos temp = thisPos;
    myList->insertHead(temp);
}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if (myList->getSize() == 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    objPos temp = myList->getHead();
    myList->removeHead();
    return temp;
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if (myList->getSize() == 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    return myList->getHead();
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosSHLinkedList method can realize this operation.
    return myList->getSize();
}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    
}