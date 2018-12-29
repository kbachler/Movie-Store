//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include <iostream>
#include "movie.h"

using namespace std;

//  Borrow class member header file

class Borrow : public Command {
  friend ostream & operator<< (ostream & output, const Borrow & br);

  public:
    Borrow();
    Borrow(int id, string in);
    virtual ~Borrow();
    virtual Borrow * createCommand(string action);
    virtual bool execute(Store * theStore);
    virtual ostream & display(ostream & output) const;

  private:
    int customerID;
    string details;
    Movie * borrowed;
    string fullDetails;
};
#endif
