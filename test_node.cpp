//Gezim Saciri & Ben Liepert
//test file for node class

#include <iostream>
#include <string>
#include <cassert>
#include "node.h"
using namespace std;

void test_constructor()
{
  Node<int> A;
  assert(A.toString() == "( )");
  cout << "Constructor passed!\n";
}

void test_copyConstructor()
{
  Node<int> A;
  int x = 5;
  A.key = &x;
  assert(A.toString() == "(5)");


  Node<int> B(A);
  assert(B.toString() == "(5)");
  cout << "Copy constructor passed!\n";
}

void test_lessThanOp()
{
  Node<int> A;
  int x = 5;
  A.key = &x;
  assert(A.toString() == "(5)");


  Node<int> B(A);
  assert(B.toString() == "(5)");
  int y = 3;
  B.key = &y;
  assert(B.toString() == "(3)");

  assert(B < A);
  assert(!(A < B));
  cout << "Less than operator passed!\n";
}


int main()
{
    test_constructor();
    test_copyConstructor();
    test_lessThanOp();

    cout << "All Tests Passed!\n";
}
