//
//  queue.h
//  test
//
//  Created by Aastha Goel on 30/04/20.
//  Copyright © 2020 Aastha Goel. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include "List.h"

template< typename QUEUETYPE>
class Queue :private List<QUEUETYPE>{
public:
    //enqueue calls List member function insertAtBlock
    void enqueue(const QUEUETYPE& data){
        insertAtBack(data);
    }
    
    //dequeue calls list member function removeFromFront
    bool dequeue(QUEUETYPE& data){
        return removeFromFront(data);
    }
    
    //isQueueEmpty calls List member function isEmpty
    bool isQueueEmpty() const {
        return this->isEmpty();
    }
    
    //printQueue calls list member function print
    void printQueue() const{
        this->print();
    }
}


#endif /* queue_h */
