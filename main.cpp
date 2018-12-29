//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include <iostream>
#include "movie.h"
#include "comedy.h"
#include "store.h"

//  Main for the movie store assignment. Reads in files
//  and builds the Store

using namespace std;

int main(){
  Store a;
  a.buildMovies("data4movies.txt");
  a.buildCustomers("data4customers.txt");
  a.readCommands("data4commands.txt");
  return 0;
}
