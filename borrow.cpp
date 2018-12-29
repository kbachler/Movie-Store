//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "borrow.h"
#include <iostream>
#include <sstream>

//  Borrow class member function definitions

using namespace std;

ostream & operator<<(ostream & output, const Borrow & br) {
  return br.display(output);
}

Borrow::Borrow() {
}

Borrow::Borrow(int id, string d) {
  customerID = id;
  details = d;
  borrowed = nullptr;
}

Borrow::~Borrow() {
  delete borrowed;
}

Borrow * Borrow::createCommand(string action) {
  stringstream info(action);
  int id;
  string dvdCheck;
  string dtls = "";
  info.ignore();
  info >> id;
  info >> dvdCheck;
  //  Make sure that we have a DVD media type:
  if (dvdCheck != "D") {
    cerr << "Invalid Media Type: " << action << endl;
    return nullptr;
  }
  getline(info, dtls);

  Borrow * retVal = new Borrow(id, dtls);
  retVal->fullDetails = action;
  return retVal;
}

bool Borrow::execute(Store * theStore) {
  if (theStore->checkValid(customerID) == true) {
    borrowed = theStore->borrowMovie(details);
    if (borrowed != nullptr) {
      theStore->addCommand(this, customerID);
      return true;
    } else {
      return false;
    }
  } else {
    cerr << "Customer ID not found: " << customerID << endl;
    return false;
  }
}

ostream & Borrow::display(ostream & output) const {
  output << "B" << fullDetails;
  return output;
}
