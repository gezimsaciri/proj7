//Gezim Saciri & Ben Liepert
//dict.h
#ifndef DICT_H
#define DICT_H

#include <iostream>
#include "rbt.h"

template <class KeyType>
class Dictionary : public RedBlackTree<KeyType>
{
  public:
    Dictionary():RedBlackTree<KeyType>() { } //default
    Dictionary(const Dictionary<KeyType>& d):RedBlackTree<KeyType>(d) { }

    KeyType*    get(const KeyType& k); //want const at the end here?
    void        insert(KeyType *k);
    void        remove(const KeyType& k);
    bool        empty() const { return RedBlackTree<KeyType>::empty(); }
};

#include "dict.cpp"

#endif
