//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "drama.h"
#include <sstream>
#include <iostream>

//  Drama class member function definitions.

using namespace std;

ostream & operator<< (ostream & output, const Drama & mv) {
  return mv.display(output);
}

Drama::Drama() {
}

Drama::Drama(string t, int y, string d) : Movie(t, y, d) {}

Drama * Drama::createMovie(string data) {
  stringstream info(data);
  int year;
  string title, director;
  getline(info, director, ',');
  info.ignore();
  getline(info, title, ',');
  info.ignore();
  info >> year;

  if (year < 0) return nullptr;
  Drama * retVal = new Drama(title, year, director);
  retVal->movieType = "D";
  return retVal;
}

Drama * Drama::createCompareMovie(string data) {
  stringstream info(data);
  string director, title;
  getline(info, director, ',');
  info.ignore();
  getline(info, title, ',');

  Drama * retVal = new Drama(title, 0, director);
  retVal->movieType = "D";
  return retVal;
}

bool Drama::operator== (const Movie & rhs) {
  const Drama & temp = static_cast<const Drama &>(rhs);
  if (this->director == temp.director && this->title == temp.title) {
    return true;
  }
  return false;
}

bool Drama::operator> (const Movie & rhs) {
  const Drama & temp = static_cast<const Drama &>(rhs);
  if (this->director > temp.director) {
    return true;
  } else if (this->director == temp.director) {
    if (this->title > temp.title) {
      return true;
    }
  }
  return false;
}

ostream & Drama::display(ostream & output) const {
  output << getDirector() << ", " << getTitle() << ", " <<
  getYear();
  return output;
}
