//  Copywrite Kayla Bachler
//  Kayla Bachler
//  CSS343 Assignment #4
//  3-11-2018

#include "customer.h"

using namespace std;

//  Customer class definitions

ostream & operator<< (ostream & output, const Customer & cs) {
  return cs.display(output);
}

Customer::Customer() {
}

Customer::Customer(int id, string last, string first) {
  customerID = id;
  lastName = last;
  firstName = first;
}

Customer::~Customer() {
  for (int i = 0; i < history.size(); i++) {
    delete history[i];
  }
  history.clear();
}

void Customer::addCommand(Command * cmd){
  if (cmd != NULL) {
    history.push_back(cmd);
  }
}

bool Customer::operator== (const Customer & rhs) const {
  return (this->customerID == rhs.customerID);
}

ostream & Customer::display(ostream & output) const {
  output << customerID << " History:" << endl;
  for (int i = 0; i < history.size(); i++) {
    output << *history[i] << endl;
  }
  return output;
}
