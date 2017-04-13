// Ben Liepert & Gezim Saciri
// source file for RedBlackTree class
#include <iostream>
#include <sstream>
#include <cassert>
#include "rbt.h"
using namespace std;

//=====================================
// default constructor
template <class KeyType>
RedBlackTree<KeyType>::RedBlackTree(){
  root = NULL;
}

//=====================================
// destructor
template <class KeyType>
RedBlackTree<KeyType>::~RedBlackTree(){
  destroy(root); //I think this is all we need as opposed to the above
}

//=====================================
// copy constructor
// pre condition: A RedBlackTree that we will copy into this
// post condition: A new RedBlackTree that is a copy of the one passed in
template <class KeyType>
RedBlackTree<KeyType>::RedBlackTree(const RedBlackTree<KeyType>& rbt){
  root = NULL;
  Node<KeyType>* traverse = rbt.root;
  copy(traverse);
}

//=====================================
// get
// pre condition: A RedBlackTree and a KeyType k that it will search for
// post condition: The RedBlackTree(unchanged) and will return value key or NULL
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::get(const KeyType& k) {
  Node<KeyType>* found = search(k);
  return (found == NULL) ? NULL : found->key; //NULL if not in rbt, key otherwise
}

//=====================================
// insert
// pre condition: A RedBlackTree to insert values into, and a KeyType pointer k to insert
// post condition: The RedBlackTree with the KeyType pointer k inserted into the tree
template <class KeyType>
void  RedBlackTree<KeyType>::insert(KeyType *k){
  Node<KeyType> *par = NULL; //keep track of parent w/this
  Node<KeyType> *c = root;
  while (c != NULL){
    par = c;
    if (*k < *c->key){ //need to deref to compare vals
      c = c->leftChild;
    }else{
      c = c->rightChild;
    }
  }
  Node<KeyType> *i = new Node<KeyType>; //create node to insert
  i->key = k; //key stores a pointer, k is a ptr
  i->parent = par;
  i->leftChild = NULL;
  i->rightChild = NULL;
  if (par == NULL){ //empty tree
    root = i;
  }else if(*i->key < *par->key){
    par->leftChild = i;
  }else{
    par->rightChild = i;
  }
}

//=====================================
// remove
// pre condition: A RedBlackTree that contains values(else EmptyError) and a value k to remove
// post condition: The RedBlackTree with the value k removed from it
template <class KeyType>
void  RedBlackTree<KeyType>::remove(const KeyType& k){
  if(root == NULL){ //can't remove if empty
    throw EmptyError();
  }
  Node<KeyType>* par = NULL;
  Node<KeyType>* n = root;
  while (k != *n->key){ //get node to be removed
    par = n;
    if (k < *n->key){
      n = n->leftChild;
    }else{
      n = n->rightChild;
    }
  }
  if(n->leftChild == NULL){
    transplant(n, n->rightChild);
  }else if(n->rightChild == NULL){
    transplant(n, n->leftChild);
  }else{
    Node<KeyType>* successor = search(*min(n->rightChild));
    if(successor->parent != n){
      transplant(successor, successor->rightChild);
      successor->rightChild = n->rightChild;
      successor->rightChild->parent = successor;
    }
    transplant(n, successor);
    successor->leftChild = n->leftChild;
    successor->leftChild->parent = successor;
    delete n;
  }
}

//=====================================
// maximum
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree(unchanged) and returns the maximum key
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::maximum() const{
  if (root == NULL){
    throw EmptyError();
  }
  Node<KeyType>* n = root;
  while(n->rightChild != NULL){
    n = n->rightChild;
  }
  return n->key;
}

//=====================================
// minimum
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree and returns the minimum value
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::minimum()const{
  if (root == NULL){
    throw EmptyError();
  }
  Node<KeyType>* n = root;
  while(n->leftChild != NULL){
    n = n->leftChild;
  }
  return n->key;
}
//=====================================
// min (private)
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree and returns the minimum value
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::max(Node<KeyType> *node) const{
  if (node == NULL){
    throw EmptyError();
  }
  Node<KeyType>* n = node;
  while(n->rightChild != NULL){
    n = n->rightChild;
  }
  return n->key;
}
//=====================================
// max (private)
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree and returns the minimum value
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::min(Node<KeyType>* node) const{
  if (node == NULL){
    throw EmptyError();
  }
  Node<KeyType>* n = node;
  while(n->leftChild != NULL){
    n = n->leftChild;
  }
  return n->key;
}

//=====================================
// successor
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree(uchanged) and returns the successor
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::successor(const KeyType& k){
  if (root == NULL){
    throw EmptyError();
  }
  if(k == *maximum()){ // max has no successor
    return NULL;
  }
  Node<KeyType>* n = search(k); //get the node whose value is k
  Node<KeyType> *nRC = n->rightChild;
  if(nRC != NULL){
    return (min(nRC)); //make a private one now;
  }
  Node<KeyType>* par = n->parent;
  while(par != NULL && n == par->rightChild){
    n = par;
    par = par->parent;
  }
  return par->key;
}

//=====================================
// predecessor
// pre condition: A RedBlackTree with at least one value
// post condition: The RedBlackTree(uchanged) and returns the predecessor
template <class KeyType>
KeyType*  RedBlackTree<KeyType>::predecessor(const KeyType& k){
  if (root == NULL){
    throw EmptyError();
  }
  if(k == *minimum()){ //min has no predecessor
    return NULL;
  }
  Node<KeyType>* n = search(k); //get the node whose value is k
  Node<KeyType> *nLC = n->leftChild;
  if(nLC != NULL){
    return (max(nLC));
  }
  Node<KeyType>* par = n->parent;
  while(par != NULL && n == par->leftChild){
    n = par;
    par = par->parent;
  }
  return par->key;
}

//=====================================
//  assignment operator
// pre condition: A RedBlackTree to set equal to another passed in tree rbt
// post condition: The RedBlackTree which is equal to the passed in tree rbt
template <class KeyType>
RedBlackTree<KeyType>&  RedBlackTree<KeyType>::operator=(const RedBlackTree<KeyType> &rbt){
  destroy(root);
  root = NULL; //set to NULL AFTER we destroy so we can still traverse
  Node<KeyType>* traverse = rbt.root;
  copy(traverse);
}

//=====================================
//  search
// pre condition: A RedBlackTree and a value k to search for
// post condition: The RedBlackTree(unchanged) and returns the node with the value k
template <class KeyType>
Node<KeyType>*  RedBlackTree<KeyType>::search(const KeyType& k){
  Node<KeyType>* n = root;
  while(n != NULL && *n->key != k){
    if(!(*n->key < k) && (*n->key != k)){
      n = n->leftChild;
    }else{
      n = n->rightChild;
    }
  }
  return n;
}

//=====================================
//  transplant
// pre condition: A RedBlackTree and two nodes within that tree
// post condition: The RedBlackTree where the two nodes have swapped places
template <class KeyType>
void  RedBlackTree<KeyType>::transplant(Node<KeyType>* rem, Node<KeyType>* rep){
  if(rem->parent == NULL){
    root = rep;
  }else if(rem == rem->parent->leftChild){
    rem->parent->leftChild = rep;
  }else{
    rem->parent->rightChild = rep;
  }
  if(rep != NULL){
    rep->parent = rem->parent;
  }
}

//==========================================
// these three functions call the ones below
// this avoids exposing node pointers
template <class KeyType>
std::string  RedBlackTree<KeyType>::inOrder(){
  std::string tree = "{";
  return inOrd(root, tree) + " }";
}
template <class KeyType>
std::string  RedBlackTree<KeyType>::preOrder(){
  std::string tree = "{";
  return preOrd(root, tree) + " }";
}
template <class KeyType>
std::string  RedBlackTree<KeyType>::postOrder(){
  std::string tree = "{";
  return postOrd(root, tree) + " }";
}

//=====================================
// inOrd
// pre condition: A pointer node and a string tree
// post condition: Only returns the string tree which contains the keys of the nodes inOrd
template <class KeyType>
string  RedBlackTree<KeyType>::inOrd(Node<KeyType> *node, string& tree)const {
  if (node != NULL){
    inOrd(node->leftChild, tree);
    tree += (" " + node->toString());
    inOrd(node->rightChild, tree);
  }
  return tree;
}

//=====================================
// preOrd
// pre condition: A pointer node and a string tree
// post condition: Only returns the string tree which contains the keys of the nodes preOrd
template <class KeyType>
string  RedBlackTree<KeyType>::preOrd(Node<KeyType> *node, std::string& tree)const{
  if (node != NULL){
    tree += (" " + node->toString());
    inOrd(node->leftChild, tree);
    inOrd(node->rightChild, tree);
  }
  return tree;
}

//=====================================
// postOrd
// pre condition: A pointer node and a string tree
// post condition: Only returns the string tree which contains the keys of the nodes postOrd
template <class KeyType>
string  RedBlackTree<KeyType>::postOrd(Node<KeyType> *node, std::string& tree)const{
  if (node != NULL){
    inOrd(node->leftChild, tree);
    inOrd(node->rightChild, tree);
    tree += (" " + node->toString());
  }
  return tree;
}

//=====================================
// copy
// pre condition: A RedBlackTree and a node that is set to the root of the tree to copy
// post condition: The RedBlackTree that is the copy of the passed in tree
template <class KeyType>
void RedBlackTree<KeyType>::copy(Node<KeyType>* traverse){
  if(traverse == NULL){
    return;
  }
  insert(traverse->key); //insert value
  copy(traverse->leftChild); //go left
  copy(traverse->rightChild);//go right
}

//=====================================
// destroy
// pre condition: A RedBlackTree and a node to the root of that tree
// post condition: Deallocates the memory of the RedBlackTree
template <class KeyType>
void RedBlackTree<KeyType>::destroy(Node<KeyType>* traverse){
  if(traverse == NULL){
    return;
  }
  delete(traverse->leftChild);
  delete(traverse->rightChild);
  delete traverse; //get to bottom of left or right subtree, delete, recursive call
}
