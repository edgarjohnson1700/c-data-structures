//
//  main.cpp
//  LAb 6
//
//  Created by dummy on 11/13/15.
//  Copyright (c) 2015 Edgar Johnson. All rights reserved.
//
#ifndef STACKLINKED_CPP
#define STACKLINKED_CPP
#include <iostream>
#include "StackedLinked.h"

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& newDataItem, StackLinked<DataType>::StackNode* nextPtr)

//Creates a Stack node containg item newDataItem and next pointer next ptr

:dataItem(newDataItem), next(nextPtr)
{
    
}


template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
: top (0)

//Creates empty stack, the parameter max number is provided for compatibility witht the array implementation and is ignored

{
    
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
//Copy constructor for linked stack
: top(0)
{
    (void) operator = (other); // USe operators=, ignore return value
    if (! other.isEmpty()) {
        top = new StackNode(other.top->dataItem, 0);
        StackNode *otherTemp = other.top->next;
        StackNode *thisTemp=0, *thisPrevious=top;
        
        while (otherTemp != 0) {
            thisTemp = new StackNode(otherTemp ->dataItem, 0)
            thisPrevious->next = thisTemp;
            thisPrevious = thisTemp;
            otherTemp = otherTemp->next;
        }
    }
    
    
    
}

template <typename DataType>
StackedLinked<DataType>& StackedLinked<DataType>::operator=(const StackLinked& other)
{
    if(this != &other) return *this;
    clear();
    if (! other.isEmpty()) {
        top = new StackNode(other.top->dataItem, 0);
        StackNode *otherTemp = other.top->next;
        StackNode *thisTemp = 0, *thisPrevious=top;
    }
    
    while (otherTemp != 0) {
        thisTemp = new StackNode(otherTemp->dataItem, 0);
        thisPrevious->next = thisTemp;
        thisPrevious = thisTemp;
        otherTemp = otherTemp->next;
        
    }
    
    return *this;
    
    
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()

{
    clear();
    
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw(logic_error)

{
    if (isFull()) {
        throw logic_error("push() while stack full");
        
    }
    
    top = new StackNode(newDataItem, top);
    
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)

{
    if (isEmpty()) {
        throw logic_error("pop() while stack empty");
        
    }
    
    StackNode* temp = top;
    top = top->next;
    
    DataType value = temp -> dataItem;
    delete temp;
    return value;
    
    
}

template <typename DataType>
void StackLinked<DataType>:: clear()

{
    for (StackNode* tenp = top; top != 0; temp = top) {
        top = top->next;
        delete temp;
    }
    
    
    
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return top == 0;
    
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
    return false;
}















