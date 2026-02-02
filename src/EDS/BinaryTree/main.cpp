#include "binarytree.cpp"
#include <iostream>

int main() {
    BinaryTree<char> r('a');   
    r.getRoot()->insertLeft('b');   
    r.getRoot()->insertRight('c'); 

    r.getRoot()->left->insertLeft('d');   
    r.getRoot()->left->insertRight('e');   

    r.getRoot()->right->insertLeft('f'); 

    std::cout << r.getRoot()->data << std::endl;   
    std::cout << r.getRoot()->left->data << std::endl;   
    std::cout << r.getRoot()->right->data << std::endl; 
      
    std::cout << r.getRoot()->left->left->data << std::endl;   
    std::cout << r.getRoot()->left->right->data << std::endl;   
    std::cout <<r.getRoot()->right->left->data << std::endl;

    return 0;
}