//Gezim Saciri & Ben Liepert
//test file for the Dictionary class

#include <iostream>
#include <sstream>
#include "dict.h"
#include <cassert>
using namespace std;

void test_empty(){
  Dictionary<string> d;
  assert(d.empty());
  string a = "alpaca";
  d.insert(&a);
  assert(!d.empty());
  d.remove(a);
  assert(d.empty());
}

void test_get(){
  Dictionary<string> d;
  assert(d.empty());
  string a = "hi my name is Drew Bapst";
  d.insert(&a);
  assert(d.get(a) == &a);
  string b = "hi my name is Drew Bapst";
  assert(d.get(b) == &a);
  d.remove(a);
  assert(d.get(b) == NULL);
  assert(d.get(a) == NULL);
}

void test_insert(){
  Dictionary<string> d;
  assert(d.empty());
  string a = "alphabet";
  string b = "barnacle";
  d.insert(&a);
  assert(!d.empty());
  d.insert(&b);
}

void test_remove(){
  Dictionary<string> d;
  assert(d.empty());
  string a = "skert";
  d.insert(&a);
  string b = "drewbapst";
  d.insert(&b);
  string c = "a";
  string d2 = "gezim";
  string e = "mami";
  d.insert(&c);
  d.insert(&d2);
  d.insert(&e);
  d.remove(c);
  assert(d.get(c) == NULL);
  d.remove(d2);
  assert(d.get(d2) == NULL);
  d.remove(b);
  assert(d.get(b) == NULL);
  d.remove(a);
  assert(d.get(a) == NULL);
  d.remove(e);
  assert(d.empty());
  assert(d.get(e) == NULL);
}

int main(){
  test_empty();
  test_get();
  test_insert();
  test_remove();
  cout << "Dictionary: All Tests Passed!\n";
  return 0;
}
