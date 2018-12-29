//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "inventory.h"
#include <iostream>

//  Inventory class member function definitions.

using namespace std;

ostream & operator<< (ostream & output, const Inventory & in) {
  return in.display(output);
}

Inventory * Inventory::createCommand(string details) {
  Inventory * retVal = new Inventory();
  return retVal;
}

bool Inventory::execute(Store * theStore) {
  theStore->printMovies();
  return true;
}

ostream & Inventory::display(ostream & output) const {
  return output;
}
