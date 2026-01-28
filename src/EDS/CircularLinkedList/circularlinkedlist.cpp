#ifndef CIRCULARLINKEDLIST_CPP 
#define CIRCULARLINKEDLIST_CPP 

#include "circularlinkedlist.h"

template<typename T> 
CircularLinkedList<T>::CircularLinkedList() : begin(nullptr), end(nullptr), count(0){ } 

template<typename T> 
CircularLinkedList<T>::~CircularLinkedList(){
    Node<T>* del = begin; 
    end->next = nullptr;
    while (begin){ 
        begin = begin->next; 
        delete del; 
        del = begin; 
    } 
} 

template<typename T> 
Node<T>* CircularLinkedList<T>::makeNode(const T &value) { 
    return new Node<T>(value); 
} 

template<typename T> 
void CircularLinkedList<T>::insert(int pos, const T &value) { 
    if(pos < 0 || pos > count){ 
        cout << "Error! The position is out of range." << endl; 
        return; 
    } 
    
    Node<T>* add = makeNode(value);

    if(pos == 0){ 
        if(count == 0){
            begin = add;
            end = add;
            add->next = begin;
        } else {
            add->next = begin;
            begin = add;
            end->next = add;
        }
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next;
        } 
        add->next = cur->next; 
        cur->next = add;

        if(pos == count) {
            end = add;
        }
    } 

    count++; 
}

template<typename T>
void CircularLinkedList<T>::erase(int pos) {
    if(pos < 0 || pos >= count){
        cout << "Error! The position is out of range." << endl; 
        return; 
    }

    if(pos == 0){
        Node<T>* del = begin;
        if(count <= 1){
            begin = nullptr;
            end = nullptr;
        } else {
            begin = begin->next;
            end->next = begin;
        } 
        delete del; 
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next; 
        } 
        Node<T>* del = cur->next;
        cur->next = del->next;

        if(pos == count - 1)
            end = cur;
        delete del;
    }  
    
    count--;
}

template<typename T>
T& CircularLinkedList<T>::get(int pos) const {
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
void CircularLinkedList<T>::print() const {
    if (count == 0) {
        cout << "List is empty" << endl;
        return;
    }

    Node<T>* cur = begin;
    while(cur != end) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << cur->data << endl;
}

template<typename T> 
int CircularLinkedList<T>::size() const { 
    return count; 
} 

#endif