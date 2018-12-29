//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef COMMAND_H
#define COMMAND_H

#include "store.h"
#include <iostream>

using namespace std;



class Command {
  friend ostream & operator<< (ostream & output, const Command & cm) {
    return cm.display(output);
  }

  public:
    Command() {};
    virtual ~Command() {};
    virtual Command * createCommand(string action) = 0;
    virtual bool execute(Store * theStore) = 0;
    virtual ostream & display(ostream & output) const = 0;

  private:
};
#endif
