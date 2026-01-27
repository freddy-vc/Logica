#ifndef LIST_H 
#define LIST_H 

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
class List {
    private:
        Node<T>* begin;
        int count;
        Node<T>* makeNode(const T& value);
    public:
        List();
        ~List();
        void insert(int pos, const T& value);
        void erase(int pos);
        void reverse();
        void sort();
        T& get(int post) const;
        void print() const;
        
        int size() const;
};

#endif