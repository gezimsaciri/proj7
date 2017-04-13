// Ben Liepert & Gezim Saciri
// rbt.h
#ifndef RBT_H
#define RBT_H

#include <iostream>
#include "node.h"

template <class KeyType>
class RedBlackTree
{
  public:
    RedBlackTree();
    ~RedBlackTree();
    RedBlackTree(const RedBlackTree<KeyType>& rbt);

    bool               empty() const { return root == NULL; } // return true if empty; false o/w
    KeyType *          get(const KeyType& k); // return first element with key equal to k
    void               insert(KeyType *k); // insert k into the tree
    void               remove(const KeyType& k); // delete first element with key equal to k
    KeyType *          maximum() const; // return the maximum element
    KeyType *          minimum() const; // return the minimum element
    KeyType *          successor(const KeyType& k); // return the successor of k
    KeyType *          predecessor(const KeyType& k); // return the predecessor of k

    std::string        inOrder(); // return string of elements from an inorder traversal
    std::string        preOrder(); // return string of elements from a preorder traversal
    std::string        postOrder(); // return string of elements from a postorder traversal

    RedBlackTree&  operator=(const RedBlackTree<KeyType> &rbt);

  private:
    Node<KeyType>* root; //bst's root
    Node<KeyType>* nil; //nil pointer
    std::string        inOrd(Node<KeyType> *node, std::string &tree) const;
    std::string        preOrd(Node<KeyType> *node, std::string &tree) const;
    std::string        postOrd(Node<KeyType> *node, std::string &tree) const;

    Node<KeyType>*     search(const KeyType& k); //find a ptr to the node whose key = k
    void               transplant(Node<KeyType>* rem, Node<KeyType>* rep); //variables in function call subject to change
    KeyType *          min(Node<KeyType> *node) const; // return the minimum element
    KeyType *          max(Node<KeyType> *node) const; // return the maximum element

    void               copy(Node<KeyType>* node); //creates a copy of a rbt with the root of another bst
    void               destroy(Node<KeyType>* node);
};

class EmptyError { };

#include "rbt.cpp"

#endif
