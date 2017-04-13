//Gezim Saciri & Ben Liepert
//test file for RedBlackTree class
#include <iostream>
#include <sstream>
#include "rbt.h"
#include <cassert>
using namespace std;

/*
void test_empty(){
  RedBlackTree<int> A;
  assert(A.empty());
  int a = 5;
  A.insert(&a);
  assert(!A.empty());
  int b = 77;
  A.insert(&b);
  assert(!A.empty());
}

void test_copy(){
  RedBlackTree<int> A;
  assert(A.empty());
  int a = 5, b = 3, c = 4, d = 7, e = 6, f = 9, j = 2, k = 1;
  A.insert(&a);
  A.insert(&b);
  A.insert(&c);
  A.insert(&d);
  A.insert(&e);
  A.insert(&f);
  A.insert(&j);
  A.insert(&k);
  RedBlackTree<int> B(A);
  assert(A.inOrder() == B.inOrder());
  assert(A.preOrder() == B.preOrder());
  assert(A.postOrder() == B.postOrder());
}

void test_get(){
  RedBlackTree<float> A;
  assert(A.empty());
  float a = 1.3;
  float b = 2.7;
  float c = 2.959;
  float d = 155.66;
  A.insert(&a);
  A.insert(&d);
  float i = 10.73;
  float j = 10.73;
  A.insert(&i);
  float* k = A.get(j);
  assert(&i == k);
  A.insert(&b);
  A.insert(&c);
  float l = -11.373;
  float m = -11.373;
  A.insert(&l);
  float *o = A.get(m);
  assert(&l == o);
}

void test_insert(){
  RedBlackTree<int> A;
  assert(A.empty());
  int i = 18;
  A.insert(&i);
  assert(!A.empty());
  int j = 50002;
  A.insert(&j);
  assert(!A.empty());
}

void test_remove(){
  RedBlackTree<int> A;
  int a = 1;
  A.insert(&a);
  A.remove(a);
  assert(A.empty());
  assert(A.inOrder() == "{ }");
  assert(A.preOrder() == "{ }");
  assert(A.postOrder() == "{ }");
  int b = 2;
  A.insert(&b);
  int c = 3;
  A.insert(&c);
  int d = 4;
  A.insert(&d);
  A.remove(d);
  assert(A.inOrder() == "{ (2) (3) }");
  int e = 5;
  A.insert(&e);
  int f = 6;
  A.insert(&f);
  int g = 7;
  A.insert(&g);
  int j = 8;
  A.insert(&j);
  A.remove(e);
  assert(A.get(e) == NULL);
  RedBlackTree<int> B;
  int h = 2;
  try{
    B.remove(h);
    assert(false);
  }catch(EmptyError e){
    //do nothing
  }
  int k = 10;
  int l = 3;
  int m = -8;
  int n = 16;
  int o = 2;
  int p = 4;
  int q = 17;
  B.insert(&p);
  B.insert(&o);
  B.insert(&l);
  B.insert(&m);
  B.insert(&n);
  B.insert(&k);
  B.insert(&q);
  B.remove(q);
  assert(B.get(q) == NULL);
  B.remove(p);
  assert(B.get(p) == NULL);
  B.remove(m);
  B.remove(l);
  B.remove(k);
  B.remove(n);
  B.remove(o);
  assert(B.empty());
}

void test_maximum(){
  RedBlackTree<int> A;
  assert(A.empty());
  int i,j,k,l,m;
  i = 15;
  A.insert(&i);
  assert(!A.empty());
  assert(*A.maximum() == 15);
  j = -1;
  A.insert(&j);
  assert(*A.maximum() == 15);
  k = 16;
  A.insert(&k);
  assert(*A.maximum() == 16);
  l = -150;
  A.insert(&l);
  assert(*A.maximum() == 16);
  m = 1600;
  A.insert(&m);
  assert(*A.maximum() == 1600);
  assert(!A.empty());
}

void test_minimum(){
  RedBlackTree<int> A;
  assert(A.empty());
  int i,j,k,l,m;
  i = 15;
  A.insert(&i);
  assert(!A.empty());
  assert(*A.minimum() == 15);
  j = -1;
  A.insert(&j);
  assert(*A.minimum() == -1);
  k = 16;
  A.insert(&k);
  assert(*A.minimum() == -1);
  l = -150;
  A.insert(&l);
  assert(*A.minimum() == -150);
  m = 1600;
  A.insert(&m);
  assert(*A.minimum() == -150);
  assert(!A.empty());
}

void test_successor(){
  RedBlackTree<int> A;
  int a = 5;
  A.insert(&a);
  int b = 2;
  A.insert(&b);
  int c = 8;
  A.insert(&c);
  assert(A.successor(c) == NULL);
  assert(A.successor(a) == &c);
  int d = 4;
  A.insert(&d);
  int e = 1;
  A.insert(&e);
  int f = 6;
  A.insert(&f);
  assert(A.successor(e) == &b);
  assert(A.successor(c) == NULL);
  assert(A.successor(f) == &c);
  assert(A.successor(b) == &d);
  int g = 7;
  A.insert(&g);
  int j = 3;
  A.insert(&j);
  assert(A.successor(d) == &a);
}

void test_predecessor(){
  RedBlackTree<int> A;
  int a = 5;
  A.insert(&a);
  int b = 2;
  A.insert(&b);
  int c = 8;
  A.insert(&c);
  assert(A.predecessor(c) == &a);
  assert(A.predecessor(b) == NULL);
  int d = 4;
  A.insert(&d);
  int e = 1;
  A.insert(&e);
  int f = 6;
  A.insert(&f);
  assert(A.predecessor(f) == &a);
  assert(A.predecessor(e) == NULL);
  int g = 7;
  A.insert(&g);
  int j = 3;
  A.insert(&j);
  assert(A.predecessor(g) == &f);
  assert(A.predecessor(a) == &d);
}

void test_inOrder(){
  RedBlackTree<int> A;
  assert(A.inOrder() == "{ }");
  assert(A.empty());
  int i = 999;
  A.insert(&i);
  assert(A.inOrder() == "{ (999) }");
  int j = -15;
  A.insert(&j);
  assert(A.inOrder() == "{ (-15) (999) }");
  assert(!A.empty());
  int k = 1055;
  A.insert(&k);
  assert(A.inOrder() == "{ (-15) (999) (1055) }");
}

void test_preOrder(){
  RedBlackTree<int> A;
  assert(A.preOrder() == "{ }");
  assert(A.empty());
  int i = 999;
  A.insert(&i);
  assert(A.preOrder() == "{ (999) }");
  int j = -15;
  A.insert(&j);
  assert(A.preOrder() == "{ (999) (-15) }");
  assert(!A.empty());
  int k = 1055;
  A.insert(&k);
  assert(A.preOrder() == "{ (999) (-15) (1055) }");
}

void test_postOrder(){
  RedBlackTree<int> A;
  assert(A.postOrder() == "{ }");
  assert(A.empty());
  int i = 999;
  A.insert(&i);
  assert(A.postOrder() == "{ (999) }");
  int j = -15;
  A.insert(&j);
  assert(A.postOrder() == "{ (-15) (999) }");
  assert(!A.empty());
  int k = 1055;
  A.insert(&k);
  assert(A.postOrder() == "{ (-15) (1055) (999) }");
}

void test_assignment(){
  RedBlackTree<int> A;
  assert(A.empty());
  int a = 5, b = 3, c = 4, d = 7, e = 6, f = 9, j = 2, k = 1;
  A.insert(&a);
  A.insert(&b);
  A.insert(&c);
  A.insert(&d);
  A.insert(&e);
  A.insert(&f);
  A.insert(&j);
  A.insert(&k);
  RedBlackTree<int> B; //can't just do = A here;
  int l = 150, m = -15, n = 77;
  B.insert(&l);
  B.insert(&m);
  B.insert(&n);
  B = A;
  assert(A.inOrder() == B.inOrder());
  assert(A.preOrder() == B.preOrder());
  assert(A.postOrder() == B.postOrder());
}
*/
int main(){
  /*
  test_copy();
  test_assignment();
  test_empty();
  test_get();
  test_insert();
  test_remove();
  test_maximum();
  test_minimum();
  test_successor();
  test_predecessor();
  test_inOrder();
  test_preOrder();
  test_postOrder();
  cout << "Binary Search Tree: All Tests Passed!\n";
  */
  return 0;
}
