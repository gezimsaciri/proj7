//Gezim Saciri & Ben Liepert
//source file for dict.h
#include <iostream>
#include <string>
#include <sstream>
#include "dict.h"
using namespace std;

//=====================================
// get
template <class KeyType>
KeyType*  Dictionary<KeyType>::get(const KeyType& k){
  return RedBlackTree<KeyType>::get(k);
}

//=====================================
// insert
template <class KeyType>
void  Dictionary<KeyType>::insert(KeyType *k){
  if(RedBlackTree<KeyType>::get(*k) == NULL){ //can't double insert
    RedBlackTree<KeyType>::insert(k);
  }
}

//=====================================
// remove
template <class KeyType>
void  Dictionary<KeyType>::remove(const KeyType& k){
  RedBlackTree<KeyType>::remove(k);
}
