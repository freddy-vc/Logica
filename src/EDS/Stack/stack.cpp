#ifndef LISTSTACKQUEUE_STACK_CPP 
#define LISTSTACKQUEUE_STACK_CPP 

#include "Stack.h" 

template<typename T> 
void Stack<T>::push(const T &value) { 
    list.insert(0, value); 
} 

template<typename T> 
void Stack<T>::pop(){ 
    list.erase(0); 
} 

template<typename T> 
T& Stack<T>::top() const { 
    return list.get(0); 
} 

template<typename T> 
int Stack<T>::size() const { 
    return list.size();
}

#endif