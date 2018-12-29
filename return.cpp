//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "return.h"
#include <sstream>
#include <iostream>

//  Return class member function definitions.

ostream & operator<< (ostream & output, const Return & rn) {
  return rn.display(output);
}

Return::Return() {
}

Return::Return(int id, string d) {
  customerID = id;
  details = d;
  returned = nullptr;
}

Return::~Return() {
  delete returned;
}

//  Creates a Return command object for our Command
//  vector for each customer's history
Return * Return::createCommand(string action) {
  stringstream info(action);
  int id;
  string dvdCheck;
  string dtls = "";
  info.ignore();
  info >> id;
  info >> dvdCheck;
  //  Checks if we have a DVD media type
  if (dvdCheck != "D") {
    cerr << "Invalid Media Type: " << action << endl;
    return nullptr;
  }
  getline(info, dtls);

  Return * retVal = new Return(id, dtls);
  retVal->fullDetails = action;  // Holds full details
  return retVal;
}

//  Execute function that adds the Return command to the
//  appropriate customer's history
bool Return::execute(Store * theStore) {
  //  Checks if the customerID is valid
  if (theStore->checkValid(customerID) == true) {
    returned = theStore->returnMovie(details);
    if (returned != nullptr) {
      theStore->addCommand(this, customerID);
      return true;
    } else {
      cerr << "ERROR RETURN: Transaction type not found: " << details << endl;
      return false;
    }
  } else {
    cerr << "ERROR RETURN: Customer ID not found " << customerID << endl;
    return false;
  }
}

ostream & Return::display(ostream & output) const {
  output << "R" << fullDetails;
  return output;
}
