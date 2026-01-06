#ifndef ARRAYBASEDLIST_H
#define ARRAYBASEDLIST_H

#include <iostream>
#include "nodePool.h"
using namespace std;

/*-- ArrayBasedList.h -----------------------------------------------------
Array-based linked list using NodePool.

Implements only required operations:
- constructor / destructor
- copy constructor
- assignment operator
- insert(position)
- remove(position)
- search(item)
- display()
- size()
- isEmpty()
- getFree()

All nodes are retrieved and returned using NodePool.
--------------------------------------------------------------------------*/

class ArrayBasedList {
public:
    ArrayBasedList();
    ArrayBasedList(const ArrayBasedList &other);
    ArrayBasedList& operator=(const ArrayBasedList &other);
    ~ArrayBasedList();

    bool isEmpty() const;
    void insert(int position, const ElementType &item);
    void remove(int position);
    int search(const ElementType &item) const;
    void display() const;
    int size() const;
    int getFree() const;

private:
    int first;
    NodePool pool;

    int getNodeAt(int position) const;
};

#endif
