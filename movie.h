//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

using namespace std;

class Movie {

  friend ostream & operator<< (ostream & output, const Movie & mv);

  public:
    Movie();
    Movie(string t, int y, string d);
    virtual ~Movie() {};
    virtual Movie * createMovie(string data) = 0;
    virtual Movie * createCompareMovie(string data) = 0;
    string getMovieType() const;
    string getTitle() const;
    string getDirector() const;
    int getYear() const;
    virtual bool operator> (const Movie & rhs) = 0;
    virtual bool operator== (const Movie & rhs) = 0;
    virtual ostream & display (ostream & output) const = 0;

  protected:
    string title;
    int year;
    string director;
    string movieType;
};
#endif
