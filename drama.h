//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef DRAMA_H
#define DRAMA_H
#include <iostream>
#include "movie.h"

//  Drama class header file

using namespace std;

class Drama : public Movie {
  friend ostream & operator<< (ostream & output, const Movie & mv);

  public:
    Drama();
    Drama(string t, int y, string d);
    virtual ~Drama() {};
    virtual Drama * createMovie(string data);
    virtual Drama * createCompareMovie(string data);
    virtual bool operator== (const Movie & rhs);
    virtual bool operator> (const Movie & rhs);
    virtual ostream & display (ostream & output) const;
  private:
};
#endif
