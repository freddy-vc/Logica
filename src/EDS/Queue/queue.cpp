#ifndef COLAS_QUEUE_CPP 
#define COLAS_QUEUE_CPP 

#include "queue.h" 

template<typename T> 
void Queue<T>::queue(const T &value) { 
    list.insert(list.size(), value); 
}

template<typename T> 
void Queue<T>::dequeue(){ 
    list.erase(0); 
} 

template<typename T> 
T& Queue<T>::front() const { 
    return list.get(0); 
} 

template<typename T> 
T& Queue<T>::back() const { 
    return list.get(list.size() - 1); 
} 

template<typename T> 
int Queue<T>::size() const { 
    return list.size(); 
} 

template<typename T> 
void Queue<T>::print() const{ 
    list.print(); 
}

#endif