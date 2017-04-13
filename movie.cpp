//Gezim Saciri & Ben Liepert
//source file for movie.h
#include <iostream>
#include <sstream>
#include <string>
#include "movie.h"
using namespace std;

//==============================
// defualt constructor
Movie::Movie(){
  title = "Drew Bapst: The Musical";
  cast = "Drew Bapst  Josh Blaz  Brian Tran";
}

// =============================
// primary constructor
Movie::Movie(std::string &t, std::string &c){
  title = t;
  cast = c;
}

// =============================
// copy constructor
Movie::Movie(const Movie& m){
  title = m.title;
  cast = m.cast;
}

// =============================
// destructor
Movie::~Movie(){
 //no mem allocation
}

string Movie::toString(){
  stringstream ss;
  ss << "(" << title << ":: " << cast << ")";
  return ss.str();
}

//========================================
// < operator
bool Movie::operator<(const Movie &m){ //define comparison to return title
  return title < m.title;
}

//========================================
// != operator
bool Movie::operator!=(const Movie &m){ //define comparison to return title
  return title != m.title;
}
