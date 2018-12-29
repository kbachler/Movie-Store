//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#ifndef BSTREE_H
#define BSTREE_H

#include "movie.h"
#include <iostream>
using namespace std;

//  BSTree class member header file

class BSTree {
  friend ostream & operator<< (ostream & output, const BSTree & bst);

  public:

  struct Node {
    Movie * data;
    int stock;  // stock?
    Node * leftPtr;
    Node * rightPtr;
  };

    BSTree();
    ~BSTree();
    bool insert(Movie *&mv, const int &count);
    bool borrow(Movie * mv);
    bool returnMv(Movie * mv);
    bool isEmpty() const;
    void clearTree();
    void display(ostream & output, const Node * current) const;

  private:
    bool insertHelper(Node *& current, Movie *& mv, const int & count);
    void clearTreeHelper(Node *& current);
    bool borrowHelper(Node *& current, Movie *& mv);
    bool returnMvHelper(Node *& current, Movie *& mv);
    Node * rootPtr;
};
#endif
