//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "command.h"
#include "movie.h"

//  History class header file

using namespace std;

class History : public Command {
  friend ostream & operator<< (ostream & output, const History & hs);

  public:
    History();
    History(int id);
    virtual ~History() {};
    virtual History * createCommand(string details);
    virtual bool execute(Store * theStore);
    virtual ostream & display(ostream & output) const;

  private:
    int customerID;
};
#endif
