//Gezim Saciri & Ben Leipert
//source file for node.h
#include <iostream>
#include <string>
#include <sstream>
#include "node.h"
using namespace std;

//==============================
// defualt constructor
// pre-condition: nothing
// post-condition: creates an empty node
template <class KeyType>
Node<KeyType>::Node(){
  //errythang empty
  key = NULL;
  parent = NULL;
  leftChild = NULL;
  rightChild = NULL;
  color = BLACK;
}

// =============================
// primary constructor
// Pre-condition: nothing
// Post-condition: creates a basic node
// =============================
template <class KeyType>
Node<KeyType>::Node(KeyType &k){
  key = k.key;
  parent = NULL;
  leftChild = NULL;
  rightChild = NULL;
  color = BLACK;
}

// =============================
// copy constructor
// Pre-condition: requires an existing Node objects
// Post-condition: constructs a copy of the object passed in.
// =============================
template <class KeyType>
Node<KeyType>::Node(const Node<KeyType>& n){
  key = n.key;
  parent = n.parent;
  leftChild = n.leftChild;
  rightChild = n.rightChild;
  color = n.color;
}

// =============================
// destructor
// =============================
template <class KeyType>
Node<KeyType>::~Node(){
    // we don't use new anywhere
}

// =============================
// < operator overwrite
// Pre-condition: requires two Nodes for the comparison
// Post-condition: returns a boolean < comparison of the objects
// =============================
template <class KeyType>
bool Node<KeyType>::operator<(const Node<KeyType> &n){
    return *key < *n.key;
}

// =============================
// to string
// Pre-condition: needs a Node object
// Post-condition: object remains unchanged, returns object represented as a string
// =============================
template <class KeyType>
string Node<KeyType>::toString() const{
	stringstream ss;

  if (key == NULL){
    if(color == RED){
      ss << "(" << ", RED)";
    }else{
      ss << "(" << ", BLACK)";
    }
  }else{
    if(color == RED){
      ss << "("  << *key << ", RED)";
    }else{
      ss << "("  << *key << ", BLACK)";
    }
  }
	return ss.str();
}

template <class KeyType>
ostream& operator<<(ostream& stream, const Node<KeyType> &n ){
  stream << n.toString();
  return stream;
}
