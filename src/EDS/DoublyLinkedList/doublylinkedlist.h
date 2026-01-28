#ifndef DOUBLYLINKEDLIST_H 
#define DOUBLYLINKEDLIST_H 

#include <iostream> 
#include <cassert> 

using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;
        
        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
    private:
        Node<T>* begin;
        int count;
        Node<T>* makeNode(const T& value);
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insert(int pos, const T& value);
        void erase(int pos);
        T& get(int post) const;
        void print() const;
        void printReverse() const;
        
        int size() const;
};

#endif