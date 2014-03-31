#pragma once
#include "iostream"
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
    Queue(): beginQueue(NULL) {}
    ~Queue(){
    }
    /**
    @brief add in queque considering priory
    */
    void enqueue(T value, int priory);
    /**
    @brief pop with max priory
    */
    T dequeue();
private:
    class ExceptionWaste {};
    /**
    @brief for storing elements and modeling queue
    */
    struct Elements{
        Elements(): value(0),priory(0), next(NULL) {}
        ~Elements() {
            delete next;
        }
        T value;
        int priory;
        Elements *next;
    };
    Elements *beginQueue;
};

template <typename T>
void Queue<T>::enqueue(T value, int priory) {
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
            if (next->priory >=priory )
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
T Queue<T>::dequeue() {
    T value;
    Elements *start = beginQueue;
    if (!start->next) {
        value = start->value;
        delete start;
        return value;
    }
    Elements *prev = NULL;
    while(start->next) {
        prev = start;
        start = start->next;
        if (!start->next)
            break;
    }
    value = start->value;
    delete start;
    if (prev)
        prev->next = NULL;
    return value;

}
