//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef COMEDY_H
#define COMEDY_H
#include <iostream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
  friend ostream & operator<< (ostream & output, const Movie & mv);

  public:
    Comedy();
    Comedy(string t, int y, string d);
    virtual ~Comedy() {};
    virtual Comedy * createMovie(string data);
    virtual Comedy * createCompareMovie(string data);
    virtual bool operator== (const Movie & rhs);
    virtual bool operator> (const Movie & rhs);
    virtual ostream & display (ostream & output) const;
  private:
};
#endif
