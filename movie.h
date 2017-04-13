//Gezim Saciri & Ben Liepert
//movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

class Movie
{
  public:
    Movie();
    Movie(std::string &t, std::string &c);
    Movie(const Movie& m);
    ~Movie();

    bool operator<(const Movie &m);
    bool operator!=(const Movie &m);
    std::string toString();
    std::string title;
    std::string cast;
};

#include "movie.cpp"

#endif
