#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "binarytree.h"

template<class T> 
NodeTree<T>* NodeTree<T>::makeNode(const T &value) {   
    NodeTree<T>* temp = new NodeTree<T>;   
    temp->data = value;   
    temp->left = nullptr;   
    temp->right = nullptr;   
    return temp; 
}

template<class T> 
void NodeTree<T>::insertLeft(const T &value) {   
    if(!left){       
        left = makeNode(value);   
    }else{       
        NodeTree<T>* temp = makeNode(value);       
        temp->left = left;       
        left = temp;   
    } 
}

template<class T> 
void NodeTree<T>::insertRight(const T &value) {   
    if(!right){       
        right = makeNode(value);   
    }else{       
        NodeTree<T>* temp = makeNode(value);       
        temp->right = right;       
        right = temp;   
    } 
}

template<class T> 
BinaryTree<T>::BinaryTree(const T &value) {   
    root = root->makeNode(value); 
}

template<class T> 
BinaryTree<T>::~BinaryTree() {   
    destroy(root); 
}

template<class  T> 
void BinaryTree<T>::destroy(NodeTree<T> *ptr) {   
    if(!ptr) return;   
    
    destroy(ptr->left);   
    destroy(ptr->right);   
    delete ptr; 
}

template<class T> 
void BinaryTree<T>::setRoot(const T &value) {   
    root = root->makeNode(value); 
}

template<class T> 
NodeTree<T>* BinaryTree<T>::getRoot() {   
    return root; 
}

#endif