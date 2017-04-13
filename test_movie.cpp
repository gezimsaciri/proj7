//Ben Liepert & Gezim Saciri
//testing file for the movie class

#include <iostream>
#include <cassert>
#include "movie.h"
using namespace std;

void test_default(){
  Movie a;
  Movie b;
  Movie c;
  assert(a.title == "Drew Bapst: The Musical");
  assert(a.cast == "Drew Bapst  Josh Blaz  Brian Tran");
  assert(b.title == "Drew Bapst: The Musical");
  assert(b.cast == "Drew Bapst  Josh Blaz  Brian Tran");
  assert(c.title == "Drew Bapst: The Musical");
  assert(c.cast == "Drew Bapst  Josh Blaz  Brian Tran");
}

void test_copy(){
  Movie a;
  a.title = "Alphabet Soup 4000";
  a.cast = "Teddy Bear";
  Movie b(a);
  assert(b.title == "Alphabet Soup 4000");
  assert(b.cast == "Teddy Bear");
}

void test_init(){
  string t = "Skert: Episode III: Revenge of Young Thug";
  string c = "Young Thug  Yo Yo Ma";
  Movie a(t,c);
  assert(a.title == "Skert: Episode III: Revenge of Young Thug");
  assert(a.cast == "Young Thug  Yo Yo Ma");
  t = "Bro it's a prank";
  assert(a.title == "Skert: Episode III: Revenge of Young Thug");
  c = "So Flo Antonio";
  assert(a.cast == "Young Thug  Yo Yo Ma");
}

void test_lessThan(){
  Movie a;
  Movie b;
  a.title = "Hello Its Me, Drew Bapst";
  b.title = "Zebra Invasion IV: Revenge of the Serengeti Stripes";
  assert(a < b);
  assert(!(b < a));
}

void test_toString(){
  Movie a;
  Movie b;
  a.title = "Mr. Blaz's Day on the Tundra";
  a.cast = "Josh Blaz";
  b.title = "Need for speed: skert skert";
  b.cast = "Drew Bapst";
  assert(a.toString() == "(Mr. Blaz's Day on the Tundra:: Josh Blaz)");
  assert(b.toString() == "(Need for speed: skert skert:: Drew Bapst)");
}

int main(){
  test_default();
  test_init();
  test_copy();
  test_lessThan();
  test_toString();
  cout << "Movie: All Tests Passed!\n";
  return 0;
}
