#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct NodeTree{
    T data;
    NodeTree<T>* left;
    NodeTree<T>* right;
    NodeTree<T>* makeNode(const T& value);
    void insertLeft(const T& value);
    void insertRight(const T& value);
};

template<class T>
class BinaryTree {
    protected:
        NodeTree<T>* root;
        int count;
        void destroy(NodeTree<T>* ptr);
    public:
        BinaryTree(const T& value);
        ~BinaryTree();

        void setRoot(const T& value);
        NodeTree<T>* getRoot();
};

#endif