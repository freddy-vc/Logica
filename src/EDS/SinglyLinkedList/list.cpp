#ifndef LIST_CPP 
#define LIST_CPP 

#include "list.h"

template<typename T> 
List<T>::List() : begin(nullptr), count(0){ } 

template<typename T> 
List<T>::~List(){ 
    Node<T>* del = begin; 
    while (begin){ 
        begin = begin->next; 
        delete del; 
        del = begin; 
    } 
} 

template<typename T> 
Node<T>* List<T>::makeNode(const T &value) { 
    return new Node<T>(value); 
} 

template<typename T> 
void List<T>::insert(int pos, const T &value) { 
    if(pos < 0 || pos > count){ 
        cout << "Error! The position is out of range." << endl; 
        return; 
    } 
    
    Node<T>* add = makeNode(value);

    if(pos == 0){ 
        add->next = begin; 
        begin = add; 
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next;
        } 
        add->next = cur->next; 
        cur->next = add;
    } 

    count++; 
}

template<typename T>
void List<T>::erase(int pos) {
    if(pos < 0 || pos > count - 1){
        cout << "Error! The position is out of range." << endl; 
        return; 
    }

    if(pos == 0){
        Node<T>* del = begin; 
        begin = begin->next; 
        delete del; 
    }else{ 
        Node<T>* cur = begin; 
        for(int i = 0; i < pos - 1; i++){ 
            cur = cur->next; 
        } 
        Node<T>* del = cur->next;
        cur->next = cur->next->next;
        delete del;
    }  
    
    count--;
}

template<typename T>
void List<T>::reverse() {
    Node<T>* prev = nullptr;
    Node<T>* cur = begin;
    Node<T>* next = nullptr;

    while (cur) {
        next = cur->next;   
        cur->next = prev;   
        prev = cur;         
        cur = next;         
    }

    begin = prev;
}

template<typename T>
void List<T>::sort() {
    if (!begin || !begin->next)
        return;

    auto split = [](Node<T>* source, Node<T>** front, Node<T>** back) {
        Node<T>* slow = source;
        Node<T>* fast = source->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
    };

    auto merge = [&](Node<T>* a, Node<T>* b, auto&& merge_ref) -> Node<T>* {
        if (!a) return b;
        if (!b) return a;

        if (a->data <= b->data) {
            a->next = merge_ref(a->next, b, merge_ref);
            return a;
        } else {
            b->next = merge_ref(a, b->next, merge_ref);
            return b;
        }
    };

    auto mergeSort = [&](Node<T>* head, auto&& mergeSort_ref) -> Node<T>* {
        if (!head || !head->next)
            return head;

        Node<T>* a;
        Node<T>* b;

        split(head, &a, &b);

        a = mergeSort_ref(a, mergeSort_ref);
        b = mergeSort_ref(b, mergeSort_ref);

        return merge(a, b, merge);
    };

    begin = mergeSort(begin, mergeSort);
}

template<typename T>
T& List<T>::get(int pos) const {
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
void List<T>::print() const {
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
int List<T>::size() const { 
    return count; 
} 

#endif