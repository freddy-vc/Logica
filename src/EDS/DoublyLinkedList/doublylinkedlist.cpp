#ifndef DOUBLYLINKEDLIST_CPP 
#define DOUBLYLINKEDLIST_CPP 

#include "doublylinkedlist.h"

template<typename T> 
DoublyLinkedList<T>::DoublyLinkedList() : begin(nullptr), count(0) {} 

template<typename T> 
DoublyLinkedList<T>::~DoublyLinkedList(){ 
    Node<T>* del = begin; 
    while (begin){ 
        begin = begin->next; 
        delete del; 
        del = begin; 
    } 
} 

template<typename T> 
Node<T>* DoublyLinkedList<T>::makeNode(const T &value) { 
    return new Node<T>(value); 
} 

template<typename T> 
void DoublyLinkedList<T>::insert(int pos, const T &value) { 
    if(pos < 0 || pos > count){ 
        cout << "Error! The position is out of range." << endl; 
        return; 
    } 
    
    Node<T>* add = makeNode(value);

    if(pos == 0){ 
        if(count > 0)
            begin->prev = add;

        add->next = begin; 
        begin = add;
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next;
        } 
        add->next = cur->next; 
        cur->next = add;
        if(pos < count)
            add->next->prev = add;
        add->prev = cur;
    } 

    count++; 
}

template<typename T>
void DoublyLinkedList<T>::erase(int pos) {
    if(pos < 0 || pos > count - 1){
        cout << "Error! The position is out of range." << endl; 
        return; 
    }

    if(pos == 0){
        Node<T>* del = begin; 
        begin = begin->next;
        if(begin)
            begin->prev = nullptr;
        delete del; 
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next; 
        } 
        Node<T>* del = cur->next;
        cur->next = cur->next->next;
        if(pos < count - 1)
            cur->next->prev = cur;
        delete del;
    }  
    
    count--;
}

template<typename T>
T& DoublyLinkedList<T>::get(int pos) const {
    if(pos < 0 || pos > count - 1){ 
        cout << "Error! The position is out of range." << endl; 
        assert(false); 
    } 
    
    if(pos == 0){ 
        return begin->data; 
    }else{ 
        Node<T>* cur = begin;
        for(int i = 0; i < pos; i++) {
            cur = cur->next;
        }
        return cur->data;
    }
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    if (count == 0) {
        cout << "List is empty" << endl;
        return;
    }

    Node<T>* cur = begin;
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::printReverse() const {
    if(count == 0){ 
        cout << "List is empty." << endl;
        return; 
    } 
    Node<T>* cur = begin; 
    while(cur->next){ 
        cur = cur->next; 
    } 
    while(cur){ 
        cout << cur->data << " "; 
        cur = cur->prev; 
    }
}

template<typename T> 
int DoublyLinkedList<T>::size() const { 
    return count; 
} 

#endif