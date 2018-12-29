//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "store.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include "classics.h"
#include "customer.h"

#include <iostream>
#include <sstream>
#include <fstream>

//  Store class member function definitions.

using namespace std;

//  The Store is the container and manager for all of the 
//  store's data. This includes the entire customer base, 
//  transaction history, and item inventory.
//  Assumptions: all input is correctly formatted according to the
//  homework specification file. (Errors may exist).
Store::Store() {
  for (int i = 0; i < MAX_TYPES; i++) {
    inventory[i] = new BSTree();
    referenceMovies[i] = nullptr;
	referenceCmds[i] = nullptr;
  }

  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    customers[i] = nullptr;
  }
  //  Reference Movies for easy key lookup
  referenceMovies['C' - 'A'] = new Classics();
  referenceMovies['F' - 'A'] = new Comedy();
  referenceMovies['D' - 'A'] = new Drama();
  //  Reference Commands for easy key lookup
  referenceCmds['I' - 'A'] = new Inventory();
  referenceCmds['H' - 'A'] = new History();
  referenceCmds['B' - 'A'] = new Borrow();
  referenceCmds['R' - 'A'] = new Return();
}

Store::~Store() {
  for (int i = 0; i < MAX_TYPES; i++) {
	delete referenceMovies[i];
	delete referenceCmds[i];
    delete inventory[i];
  }
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    delete customers[i];
  }
}

//  Reads from a file each Movie, constructs it,
//  then inserts it into the hash table of Movies
//  and correct BSTree for Movie type.
void Store::buildMovies(string file) {
  ifstream theFile(file);
  if (!theFile) {
    cerr << "ERROR: Movie file could not be found!" << endl;
    return;
  }

  while (!theFile.eof()) {
    char type;
    int stock;
    string desc = "";
    theFile >> type;
    theFile.ignore();
    theFile.ignore();
    theFile >> stock;
    theFile.ignore();
    theFile.ignore();
    getline(theFile, desc, '\n');

    if (referenceMovies[static_cast<int>(type - 'A')] == nullptr) {
      cerr << "Invalid Movie Type: " << type << " " << desc << endl;
    } else {
      Movie * current =
           referenceMovies[static_cast<int>(type - 'A')]->createMovie(desc);
      if (current != NULL) {
        inventory[static_cast<int>(type - 'A')]->insert(current, stock);
      } else {
        cerr << "Invalid Movie Type: " << current << endl;
        delete current;
      }
    }
  }
}

//  Reads from a file each customer, constructs it,
//  then inserts the customer into the BSTree of customers.
void Store::buildCustomers(string file) {
  ifstream theFile(file);
  if (!theFile) {
    cerr << "ERROR: Customer file could not be found!" << endl;
    return;
  }
  int id;
  string last,first;

  while (!theFile.eof()) {
    theFile >> id;
    theFile.ignore();
    getline(theFile, last, ' ');
    getline(theFile, first, '\n');

    if (id < 0 || id > 9999) {
      cerr << "ERROR: Invaild Customer ID: " << id << endl;
    } else if (customers[id] != nullptr) {
      cerr << "ERROR: Customer ID is already taken!" << id << endl;
    } else {
      customers[id] = new Customer(id, last, first);
    }
  }
}

//  Reads from a file specific commands and constructs each command.
//  If the transaction is customer specific it will be put into the
//  customers history of Commands
void Store::readCommands(string file) {
  ifstream theFile(file);
  if (!theFile) {
    cerr << "ERROR: Command file could not be found!" << endl;
    return;
  }

  char type;
  string desc = "";
  char movieType;
  while (!theFile.eof()) {
    theFile >> type;
    getline(theFile, desc, '\n');

    if (referenceCmds[static_cast<int>(type - 'A')] == nullptr) {
      cerr << "Invalid Action Type: " << type << desc << endl;
    } else {
      Command * cm = 
        referenceCmds[static_cast<int>(type - 'A')]->createCommand(desc);
      if (cm != NULL) {
        cm->execute(this);
      } else {
        cerr << "Invalid Action Type: " << type << desc << endl;
        delete cm;
      }
    }
  }
}

void Store::printMovies() const {
  cout << "\nCurrent Inventory:" << endl;
  cout << *inventory['F' - 'A'];
  cout << *inventory['D' - 'A'];
  cout << *inventory['C' - 'A'] << endl;
}

bool Store::printCustomer(int custID) const {
  if (customers[custID] == nullptr) {
    cerr << "Customer ID not found: " << custID << endl;
    return false;
  } else {
    cout << *customers[custID] << endl;
    return true;
  }
}

bool Store::checkValid(int custID) const{
  if (customers[custID] == nullptr) {
    return false;
  }
  return true;
}

//  Function that takes in the details of a movie and
//  calls the borrow method for the intended BSTree.
Movie * Store::borrowMovie(string details) {
  stringstream info(details);
  char type;
  string desc = "";
  info.ignore();
  info >> type;
  info.ignore();
  getline(info, desc, '\n');

  if (referenceMovies[static_cast<int>(type - 'A')] == NULL) {
    cerr << "Invalid Movie Type: " << details << endl;
    return NULL;
  }
  Movie * mv = 
    referenceMovies[static_cast<int>(type - 'A')]->createCompareMovie(desc);
  if (mv != NULL) {
    bool result = inventory[static_cast<int>(type - 'A')]->borrow(mv);
    if (result == true) {
      return mv;
    } else {
      delete mv;
      return NULL;
    }
  } else {
    return NULL;
  }
}

//  Function that takes in the details of a movie and
//  calls the returnMv method for the intended BSTree.
Movie * Store::returnMovie(string details) {
  stringstream info(details);
  char type;
  string desc = "";
  info.ignore();
  info >> type;
  info.ignore();
  getline(info, desc, '\n');

  if (referenceMovies[static_cast<int>(type - 'A')] == nullptr) {
    return NULL;
  }
  Movie * mv = 
    referenceMovies[static_cast<int>(type - 'A')]->createCompareMovie(desc);
  if (mv != NULL) {
    bool result = inventory[static_cast<int>(type - 'A')]->returnMv(mv);
	if (result == true) {
      return mv;
    } else {
      delete mv;
      return NULL;
    }
  } else {
    cerr << "ERROR: Not a vaild movie item: " << desc << endl;
    return NULL;
  }
}

//  Adds a command to the customer's history of commands
void Store::addCommand(Command * cm, int custID) {
  customers[custID]->addCommand(cm);
}
