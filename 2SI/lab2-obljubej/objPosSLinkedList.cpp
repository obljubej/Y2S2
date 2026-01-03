#include "objPosSLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Singly Linked List WITHOUT DUMMY HEADER.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosSLinkedList::objPosSLinkedList(){
    listHead = nullptr;
    listSize = 0;
    persistHead = nullptr;
}

objPosSLinkedList::~objPosSLinkedList(){
    SNode* temp = listHead;
    while(temp != nullptr){
        SNode* next = temp->next;
        delete temp;
        temp = next;
    }
}

int objPosSLinkedList::getSize(){
    return listSize;
}

bool objPosSLinkedList::isEmpty(){
   return !listSize;
}

void objPosSLinkedList::insertHead(const objPos &thisPos){
    SNode* node = new SNode();
    node->data = thisPos;
    node->next = listHead;
    listHead = node;
    listSize++;
}

void objPosSLinkedList::insertTail(const objPos &thisPos){
    SNode* node = new SNode();
    node->data = thisPos;
    node->next = nullptr;
    if(listHead == nullptr){
        listHead = node;
    }else{
        SNode* temp = listHead;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
    }
    listSize++;
}

void objPosSLinkedList::insert(const objPos &thisPos, int index) {
    if (index <= 0) {
        insertHead(thisPos);
        return;
    }
    if (index >= listSize) {
        insertTail(thisPos);
        return;
    }

    SNode* node = new SNode();
    node->data = thisPos;
    
    SNode* temp = listHead;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
    listSize++;
}


objPos objPosSLinkedList::getHead() const{
    return listHead->data;
}

objPos objPosSLinkedList::getTail() const{
    SNode* temp = listHead;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

objPos objPosSLinkedList::get(int index) const{
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }if(index <= 0){
        objPos node = getHead();
        return node;
    }if(index >= listSize-1){
        objPos node = getTail();
        return node;   
    }
    SNode* temp = listHead;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

objPos objPosSLinkedList::getNext(){
    if(persistHead == nullptr){
        persistHead = listHead;
    }else{
        persistHead = persistHead->next;
    }
    return persistHead->data;
}

void objPosSLinkedList::resetReadPos(){
    persistHead = nullptr;
}

void objPosSLinkedList::set(const objPos &thisPos, int index){
    if(listSize <= 0){
        return;
    }
    if(index <= 0){
        index = 0;
    }
    if(index >= listSize-1){
        index = listSize-1;
    }
    SNode* temp = listHead;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    temp->data = thisPos;
}


objPos objPosSLinkedList::removeHead(){
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    SNode* temp = listHead;
    objPos data = temp->data;
    listHead = temp->next;
    delete temp;
    listSize--;
    return data;
}

objPos objPosSLinkedList::removeTail(){
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    SNode* temp = listHead;
    SNode* prev = nullptr;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    objPos data = temp->data;
    if(prev == nullptr){
        listHead = nullptr;
    }else{
        prev->next = nullptr;
    }
    delete temp;
    listSize--;
    return data;
}

objPos objPosSLinkedList::remove(int index){
    if(listSize <= 0){
        return objPos(-99, 0, 0, 0, 0);
    }
    if(index <= 0){
        return removeHead();
    }
    if(index >= listSize-1){
        return removeTail();
    }
    SNode* temp = listHead;
    SNode* prev = nullptr;
    for(int i = 0; i < index; i++){
        prev = temp;
        temp = temp->next;
    }
    objPos data = temp->data;
    if(prev == nullptr){
        listHead = temp->next;
    }else{
        prev->next = temp->next;
    }
    delete temp;
    listSize--;
    return data;
}

void objPosSLinkedList::printList() const{
}


