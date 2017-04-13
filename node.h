//Gezim Saciri & Ben Liepert
//node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>

enum colors {RED, BLACK};

template <class KeyType>
class Node
{
  public:
    Node();             // default constructor
    Node(KeyType &k);        // construct a Node
    Node(const Node& n);  // copy constructor
    ~Node(); // destructor

    KeyType* key; //ptr to key of our node
    Node<KeyType>* parent;
    Node<KeyType>* leftChild;
    Node<KeyType>* rightChild;
    colors color;

    std::string toString() const;
    bool operator<(const Node &n);
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const Node<KeyType> &n );

#include "node.cpp"

#endif
