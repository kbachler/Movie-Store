//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "comedy.h"
#include <sstream>
#include <iostream>

//  Comedy class member function definitions.

using namespace std;

ostream & operator<< (ostream & output, const Comedy & mv) {
  return mv.display(output);
}

Comedy::Comedy() {
}

Comedy::Comedy(string t, int y, string d) : Movie(t, y, d){}

// Comedy::~Comedy() { }

Comedy * Comedy::createMovie(string data) {
  stringstream info(data);
  int year;
  string director, title;
  getline(info, director, ',');
  info.ignore();  // ignores commas and whitespace
  getline(info, title, ',');
  info.ignore();
  info >> year;

  if (year < 0) return NULL;  // do we need?
  Comedy * retVal = new Comedy(title, year, director);
  retVal->movieType = "F";
  return retVal;
}

Comedy * Comedy::createCompareMovie(string data) {
  stringstream info(data);
  int year;
  string title;
  string dump = "";
  getline(info, title, ',');
  info.ignore();
  info >> year;

  if (year < 0) return NULL;
  Comedy * retVal = new Comedy(title, year, dump);
  retVal->movieType = "F";
  return retVal;
}

bool Comedy::operator== (const Movie & rhs) {
  const Comedy & temp = static_cast<const Comedy &>(rhs);
  if (this->title == temp.title && this->year == temp.year) {
    return true;
  }
  return false;
}

bool Comedy::operator> (const Movie & rhs) {
  const Comedy & temp = static_cast<const Comedy &>(rhs);
  if (this->title > temp.title) {
    return true;
  } else if (this->title == temp.title) {
    if (this->year > temp.year) {
      return true;
    }
  }
  return false;
}

ostream & Comedy::display(ostream & output) const {
  output << getDirector() << ", " << getTitle() << ", " <<
  getYear();
  return output;
}
