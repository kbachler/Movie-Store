//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "movie.h"
#include <iostream>
using namespace std;

//  Movie class member function definitions.

ostream & operator<< (ostream & output, const Movie & mv) {
  return mv.display(output);
}

//  Defaulf constructor for Movie object
Movie::Movie() {
  title = "";
  year = 0;
  director = "";
}

//  Constructor that takes in params
Movie::Movie(string t, int y, string d) {
  title = t;
  year = y;
  director = d;
}

string Movie::getMovieType() const {
  return movieType;
}

string Movie::getTitle() const {
  return title;
}

int Movie::getYear() const {
  return year;
}

string Movie::getDirector() const {
  return director;
}
