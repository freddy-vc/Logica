#ifndef COLAS_QUEUE_H 
#define COLAS_QUEUE_H 

#include "../SinglyLinkedList/list.h" 

template<typename T> class Queue { 
    private: 
        List<T> list; 
    public: 
        void queue(const T& value); 
        void dequeue();
        T& front() const;
        T& back() const; 
        int size() const; 
        void print() const; 
};

#endif