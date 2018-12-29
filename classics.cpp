//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "classics.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

//  Classics class member function definitions.

ostream & operator<< (ostream & output, const Classics & mv) {
  return mv.display(output);
}

Classics::Classics() {
}

Classics::Classics(string t, int y, int m, string a) {
  title = t;
  year = y;
  releaseMonth = m;
  majorActor = a;
}

string Classics::getMajorActor() const {
  return majorActor;
}

int Classics::getReleaseMonth() const {
  return releaseMonth;
}

Classics * Classics::createMovie(string data) {
  stringstream info(data);
  int yr, month;
  string director, title, actor, first, last;
  getline(info, director, ',');
  info.ignore();
  getline(info, title, ',');
  info.ignore();
  getline(info, first, ' ');
  getline(info, last, ' ');
  info >> month;
  info.ignore();
  info >> yr;
  actor = first + " " + last;

  if (year < 0) return nullptr;
  Classics * retVal = new Classics(title, yr, month, actor);
  retVal->director = director;
  retVal->movieType = "C";
  return retVal;
}

Classics * Classics::createCompareMovie(string data) {
  stringstream info(data);
  int yr, month;
  string first, last, actor;
  string dump = ""; //Don't need title here
  info >> month;
  info.ignore();
  info >> yr;
  info.ignore();
  getline(info, first, ' ');
  info >> last;
  actor = first + " " + last;

  //if (yr < 0) return nullptr;
  Classics * retVal = new Classics(dump, yr, month, actor);
  retVal->movieType = "C";
  return retVal;
}

bool Classics::operator== (const Movie & rhs) {
  const Classics & temp = static_cast<const Classics &>(rhs);
  if (this->releaseMonth == temp.releaseMonth &&
      this->year == temp.year &&
      this->majorActor == temp.majorActor) {
//cout << "FOUND A MATCH: " << temp.majorActor << endl;
    return true;
  }
//cout << "NO MATCH: " << this->majorActor << endl;
  return false;
}

bool Classics::operator> (const Movie & rhs) {
  const Classics & temp = static_cast<const Classics &>(rhs);
  if (this->year > temp.year) {
    return true;
  } else if (this->year == temp.year) {
    if (this->releaseMonth > temp.releaseMonth) {
      return true;
    } else if (this->releaseMonth == temp.releaseMonth) {
      if (this->majorActor > temp.majorActor) {
        return true;
      }
    }
  }
  return false;
}

ostream & Classics::display(ostream & output) const {
  output << getDirector() << ", " << getTitle() << ", " <<
  getMajorActor() << " " << getReleaseMonth() << " " << getYear();
  return output;
}
