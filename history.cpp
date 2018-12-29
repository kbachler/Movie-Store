//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "history.h"
#include <sstream>
#include <iostream>

//  History class member function definitions.

using namespace std;

History::History() {
  customerID = 0;
}

History::History(int id) {
  customerID = id;
}

History * History::createCommand(string details) {
  stringstream info(details);
  int custID;
  info >> custID;

  if (custID < 0 || custID > 9999) {
    return nullptr;
  } else {
    History * retVal = new History(custID);
    return retVal;
  }
}

bool History::execute(Store * theStore) {
  bool result = theStore->printCustomer(customerID);
  if (result == true) {
    theStore->addCommand(this, customerID);
    return true;
  }
  return false;
}

ostream & History::display(ostream & output) const {
  output << "";
  return output;
}

ostream & operator<< (ostream & output, const History & hs) {
  return hs.display(output);
}
