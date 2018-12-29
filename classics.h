//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"
#include <string>
#include <iostream>

//  Classics header file

class Classics : public Movie {
  friend ostream & operator<< (ostream & output, const Movie & mv);

  public:
    Classics();
    Classics(string t, int y, int m, string a);
    virtual ~Classics() {};
    string getMajorActor() const;
    int getReleaseMonth() const;
    virtual Classics * createMovie(string data);
    virtual Classics * createCompareMovie(string data);
    virtual bool operator== (const Movie & rhs);
    virtual bool operator> (const Movie & rhs);
    virtual ostream & display(ostream & output) const;

  private:
    int releaseMonth;
    string majorActor;
};
#endif
