//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include <iostream>

//  Inventory class member header file

using namespace std;

class Inventory : public Command {
  friend ostream & operator<< (ostream & output, const Inventory & in);

  public:
    Inventory() {};
    ~Inventory() {};
    virtual Inventory * createCommand(string details);
    virtual bool execute(Store * theStore);
    virtual ostream & display(ostream & output) const;

  private:
};
#endif
