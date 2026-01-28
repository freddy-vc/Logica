#ifndef CIRCULARLINKEDLIST_H 
#define CIRCULARLINKEDLIST_H 

#include <iostream> 
#include <cassert> 

using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        
        Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class CircularLinkedList {
    private:
        Node<T>* begin;
        Node<T>* end;
        int count;
        Node<T>* makeNode(const T& value);
    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void insert(int pos, const T& value);
        void erase(int pos);
        T& get(int post) const;
        void print() const;
        
        int size() const;
};

#endif