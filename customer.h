#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <iostream>
#include <string>
#include "command.h"

using namespace std;

class Customer {
  friend ostream & operator<< (ostream & output, const Customer & cs);

  public:
    Customer();
    Customer(int id, string last, string first);
    virtual ~Customer();
    void addCommand(Command * cmd);
    virtual bool operator== (const Customer & rhs) const;
    ostream & display(ostream & output) const;

  private:
    int customerID;
    string lastName;
    string firstName;
    vector<Command *> history;
};
#endif
