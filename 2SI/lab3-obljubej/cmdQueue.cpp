#include "cmdQueue.h"

#include <iostream>
using namespace std;

// Available Data Members from cmdQueue.h

// You must implement the array-based circular queue as discussed in class

// You must NOT use any existing data structures such as Lists to design the queue.


cmdQueue::cmdQueue()
{
    // Constructor
    queue = new char[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    size = 0;
    front = 0;
    end = 0;
}

cmdQueue::cmdQueue(int cap)
{
    // Additional Constructor
    queue = new char[cap];
    capacity = cap;
    size = 0;
    front = 0;
    end = 0;
}

cmdQueue::~cmdQueue()
{
    // Destructor 
    delete[] queue;
}

void cmdQueue::enqueue(char thisCmd)
{
    // Enqueue into Circular Queue
    if (size == capacity){
        return;
    }
    queue[end] = thisCmd;
    end = (end + 1) % capacity;
    size++;
}

char cmdQueue::dequeue()
{
    // Dequeue from Circular Queue
    if (size == 0){
        return '\0';
    }
    char temp = queue[front];
    front = (front + 1) % capacity;
    size--;
    return temp;
}

int cmdQueue::getSize() const
{
    // Return the size of the Queue
    return size;
}

void cmdQueue::clearQueue()
{
    // Remove all elements from the Queue
    if (size == 0){
        return;
    }
    front = 0;
    end = 0;
    size = 0;
}

void cmdQueue::printMe() const
{
    // NOT GRADED
    //  Print the contents of the Queue
    
    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
}