//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include <iostream>
#include "movie.h"

using namespace std;

class Return : public Command {
  friend ostream & operator<< (ostream & output, const Return & rn);

  public:
    Return();
    Return(int id, string in);
    virtual ~Return();
    virtual Return * createCommand(string details);
    virtual bool execute(Store * theStore);
    virtual ostream & display(ostream & output) const;

  private:
    int customerID;
    string details;
    Movie * returned;
    string fullDetails;
};
#endif
