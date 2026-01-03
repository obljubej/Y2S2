#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List WITH DUMMY HEADER here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList(){
    listHead = new DNode();
    listTail = new DNode();
    listHead->next = listTail;
    listTail->prev = listHead;
    persistHead = listHead;
    listSize = 0;
}

objPosDLinkedList::~objPosDLinkedList(){
    DNode* temp = listHead;
    while(temp != nullptr){
        DNode* next = temp->next;
        delete temp;
        temp = next;
    }
}

int objPosDLinkedList::getSize(){
    return listSize;
}

bool objPosDLinkedList::isEmpty(){
   return !listSize;
}

void objPosDLinkedList::insertHead(const objPos &thisPos){
    DNode* node = new DNode();
    node->data = thisPos;
    node->prev = listHead;
    node->next = listHead->next;
    listHead->next->prev = node;
    listHead->next = node;
    listSize++;
}

void objPosDLinkedList::insertTail(const objPos &thisPos){
    DNode* node = new DNode();
    node->data = thisPos;
    node->next = listTail;
    node->prev = listTail->prev;
    listTail->prev->next = node;
    listTail->prev = node;
    listSize++;
}

void objPosDLinkedList::insert(const objPos &thisPos, int index){
    if(index <= 0){
        insertHead(thisPos);
    }else if(index >= listSize-1){
        insertTail(thisPos);
    }else{
        DNode* node = new DNode();
        node->data = thisPos;
        DNode* temp = listHead;
        for(int i = 0; i < index; i++){//n time complexity
            temp = temp->next;
        }
        node->next = temp;
        node->prev = temp->prev;
        temp->prev->next = node;
        temp->prev = node;
        listSize++;
    }
    
}

objPos objPosDLinkedList::getHead() const{
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    return listHead->next->data;
}

objPos objPosDLinkedList::getTail() const{
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    return listTail->prev->data;
}

objPos objPosDLinkedList::get(int index) const{
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }if(index <= 0){
        return getHead();
    }if(index >= listSize-1){
        return getTail();
    }
    DNode* temp = listHead->next;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}


objPos objPosDLinkedList::getNext(){
    if(persistHead->next == listTail){
        persistHead = listHead->next;
        return objPos(-99, 0, 0, 0, 0);
    }else{
        persistHead = persistHead->next;
        return persistHead->data;
    }

}

void objPosDLinkedList::resetReadPos(){
    persistHead = listHead;
}

void objPosDLinkedList::set(const objPos &thisPos, int index) {
    if (listSize <= 0){
        return;
    }if (index <= 0) {
        listHead->next->data = thisPos;
        return;
    }if (index >= listSize - 1) {
        listTail->prev->data = thisPos;
        return;
    }
    DNode* temp = listHead->next;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->data = thisPos;
}


objPos objPosDLinkedList::removeHead() {
    if (listSize <= 0) {
        return objPos(-99, 0, 0, 0, 0);
    }
    DNode* temp = listHead->next;
    objPos data = temp->data;

    listHead->next = temp->next;
    temp->next->prev = listHead;
    
    delete temp;
    listSize--;
    return data;
}

objPos objPosDLinkedList::removeTail(){
    if(listSize == 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    DNode* temp = listTail->prev;
    listTail->prev = temp->prev;
    temp->prev->next = listTail;
    objPos data = temp->data;
    delete temp;
    listSize--;
    return data;
}

objPos objPosDLinkedList::remove(int index) {
    if (listSize <= 0) {
        return objPos(-99, 0, 0, 0, 0);
    }
    if (index <= 0) {
        return removeHead();
    }
    if (index >= listSize - 1) {
        return removeTail();
    }

    DNode* temp = listHead->next;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    objPos data = temp->data;
    delete temp;
    listSize--;
    return data;
}



void objPosDLinkedList::printList() const {
}



