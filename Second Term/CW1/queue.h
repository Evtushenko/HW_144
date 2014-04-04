#pragma once
#include <iostream>
#include "exceptionEmpty.h"
using namespace std;

/**
@brief for using private fields
*/
class QueueTest;

template <typename T>
/**
@brief template class Queue can add and pop
*/
class Queue {
friend class QueueTest;
public:
    Queue(): error(false), beginQueue(NULL) {}
    ~Queue(){
        while (beginQueue) {
            Elements *slot = beginQueue;
            if (beginQueue)
            beginQueue = beginQueue->next;
            delete slot;
        }
    }
    /**
    @brief add in queque considering priory
    */
    void enqueue(T value, int priory);
    /**
    @brief pop with max priory
    */
    T dequeue() throw(ExceptionEmpty);
private:
    bool error;
    class ExceptionWaste {};
    /**
    @brief for storing elements and modeling queue
    */
    struct Elements {
        T value;
        int priory;
        Elements *next;
    };
    Elements *beginQueue;
};

template <typename T>
void Queue<T>::enqueue(T value, int priory) {
    //cout << "adding: " << value << " " << priory << endl;
    Elements *slot = new Elements();
    slot->value = value;
    slot->priory = priory;
    slot->next = NULL;
    if (!beginQueue) {
        beginQueue = slot;
    }
    else {
        Elements *next = beginQueue;
        Elements *previous = NULL;
        while (next) {
            if (next->priory <= priory )
                break;
            next = next->next;
        }
        if (next == beginQueue) {
           slot->next = beginQueue;
           beginQueue = slot;
        }
        if (next) {
            previous = beginQueue;
            while (previous) {
                if (previous->next == next)
                    break;
                previous = previous->next;
            }
        }
        if (!next) {
            Elements *end = beginQueue;
            {
                while(end->next)
                    end = end->next;
            }
           end->next = slot;
        }
        else {
            if (next && previous)
            {
                previous->next = slot;
                slot->next = next;
            }
        }
    }
}

template <typename T>
T Queue<T>::dequeue() throw(ExceptionEmpty) {
   if (!beginQueue)
      throw ExceptionEmpty("nothing to delete\n");
   else
   {
       Elements *slot = beginQueue;
       beginQueue = beginQueue->next;
       T value = slot->value;
       delete slot;
       return value;
   }
}
