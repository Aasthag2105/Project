//
//  stack.h
//  test
//
//  Created by Aastha Goel on 30/04/20.
//  Copyright © 2020 Aastha Goel. All rights reserved.
#ifndef STACK_H
#define STACK_H
#include <deque>

template<typename T>
class Stack{
public:
    //return top element of the stack
    const T& top(){
        return stack.front();
    }
    
    //push an element onto the Stack
    void push(const T& pushValue){
        stack.push_front(pushValue);
    }
    void pop(){
        stack.pop_front();}
    
    //determine whether stack is empty
    bool isEmpty() const{
        return stack.empty();
    }
    
    //return size of stack
    size_t size() const{
        return stack.size();
    }
    
private:
    std::deque<T> stack;
};
    #endif
