#ifndef LISTSTACKQUEUE_STACK_H 
#define LISTSTACKQUEUE_STACK_H 
#include "../SinglyLinkedList/list.h" 

template<typename T> 
class Stack { 
    private: 
        List<T> list; 
    public: 
    void push(const T& value); 
    void pop(); 
    T& top() const; 
    int size() const; 
}; 

#endif //LISTSTACKQUEUE_STACK_H