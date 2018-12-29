//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <fstream>
#include <vector>
#include "bstree.h"
#include "movie.h"

using namespace std;

class Command;
class Customer;

class Store {

  public:
    Store();
    ~Store();

    void buildMovies(string file);
    void buildCustomers(string file);
    void readCommands(string file);
    void printMovies() const;
    bool parseDesc(string check) const;
    bool printCustomer(int custID) const;
    bool checkValid(int customerID) const;
    Movie * borrowMovie(string details);
    Movie * returnMovie(string details);
    void addCommand(Command * cm, int custID);

  private:
    static const int MAX_TYPES = 26;
    static const int MAX_CUSTOMERS = 10000;

    Customer * customers[MAX_CUSTOMERS];
    BSTree * inventory[MAX_TYPES];
    Movie * referenceMovies[MAX_TYPES];
    Command * referenceCmds[MAX_TYPES];
};
#endif
