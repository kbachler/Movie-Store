//  Copyright 2018 Kayla Bachler
//  Kayla Bachler
//  CSS343 - Assignment #4
//  3-11-2018

#include "bstree.h"
#include "movie.h"
#include <iostream>

//  BSTree class member function definitions.

using namespace std;

BSTree::BSTree() {
  rootPtr = nullptr;
}

//  Destructor - calls clearTree method
BSTree::~BSTree() {
  clearTree();
  delete rootPtr;
}

//  Inserts a constructed Movie from details into the BSTree.
//  Stock is greater than 0 and mv is not null.
bool BSTree::insert(Movie *& mv, const int &count) {
  return insertHelper(rootPtr, mv, count);
}

bool BSTree::isEmpty() const {
  if (rootPtr == nullptr) {
    return true;
  }
  return false;
}

//  Calls below helper method to clear BSTree
void BSTree::clearTree() {
  if (isEmpty() == false) {
    clearTreeHelper(rootPtr);
  }
}

//  Assist method for insert that recursively finds the correct position
//  for given data. Returns true if a place for the data is found.
//  Node current begins at the root of the tree.
bool BSTree::insertHelper(Node *& current, Movie *&mv, const int &count) {
  if (current == nullptr) {
    current = new Node;
    current->stock = count;
    current->data = mv;
    current->leftPtr = nullptr;
    current->rightPtr = nullptr;
    return true;
  } else if (*current->data == *mv) {
    current->stock += count;
    return true;
  } else if (*current->data > *mv) {
    return insertHelper(current->leftPtr, mv, count);
  } else {
    return insertHelper(current->rightPtr, mv, count);
  }
}

//  Assist method that recursively shifts through tree removing Nodes.
//  Node current begins at root. Left and right child nodes must be 
//  set to NULL prior to calling this method.
void BSTree::clearTreeHelper(Node *&current) {
  if (current->leftPtr != nullptr) {
    clearTreeHelper(current->leftPtr);
  }
  if (current->rightPtr != nullptr) {
    clearTreeHelper(current->rightPtr);
  }
  delete current->data;
  delete current->leftPtr;
  delete current->rightPtr;
  delete current;
  current = nullptr;
}

//  Assist method for operator<< to display data of MovieTree recursively.
//  Recursively shift through Nodes as an inorder traversal printing 
//  each data to outStream.
void BSTree::display(ostream & output, const Node * current) const {
  if (current->leftPtr != nullptr) {
    display(output, current->leftPtr);
  }
  if (current->stock != -1) {
    output << current->data->getMovieType() << ", ";
    output << current->stock << ", ";
  }
  output << *current->data << endl;
  if (current->rightPtr != nullptr) {
    display(output, current->rightPtr);
  }
}

//  overloaded output operator for the BSTree.
ostream & operator<< (ostream & output, const BSTree & bst) {
  if (bst.rootPtr == nullptr) {
    return output;
  }
  bst.display(output, bst.rootPtr);
  return output;
}

//  Calls below borrowHelper method
bool BSTree::borrow(Movie * mv) {
  return borrowHelper(rootPtr, mv);
}

//  Searches through tree to find mv Movie to borrow.
//  updates the stock to -1, and returns out of stock
//  if no more stock is available.
bool BSTree::borrowHelper(Node *& current, Movie *& mv) {
  if (current == NULL) {
    cerr << "Invalid Movie Type: " << *mv << endl;
    return false;
  } else if (*current->data == *mv) {
    if (current->stock > 0) {
      current->stock--;
      return true;
    } else {
      cerr << "Out Of Stock: " << *mv << endl;
      return false;
    }
  } else if (*mv > *current->data) {
    return borrowHelper(current->rightPtr, mv);
  } else {
    return borrowHelper(current->leftPtr, mv);
  }
}

//  Calls below returnMvHelper
bool BSTree::returnMv(Movie * mv) {
  return returnMvHelper(rootPtr, mv);
}

//  Marks passed mv Movie as returned by searching tree
//  and adding +1 to the stock for the movie.
bool BSTree::returnMvHelper(Node *& current, Movie *& mv) {
  if (current == NULL) {
    return false;
  } else if (*current->data == *mv) {
    current->stock++;
    return true;
  } else if (*mv > *current->data) {
    return returnMvHelper(current->rightPtr, mv);
  } else {
    return returnMvHelper(current->leftPtr, mv);
  }
}
