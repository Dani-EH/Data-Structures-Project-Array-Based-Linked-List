#ifndef NODEPOOL_H
#define NODEPOOL_H

#include <iostream>
#include <string>
using namespace std;

/*-- NodePool.h ------------------------------------------------------------
Simple NodePool for an array-based linked list (no templates).
This header provides a fixed-size storage pool (NUM_NODES = 10) and basic
allocation/deallocation operations for nodes.

Constants:
  NULL_VALUE : -1 (represents null)
  NUM_NODES  : 10 (size of pool)

Node structure:
  - data : ElementType (string)
  - next : int (index of next node or NULL_VALUE)

Functions / Methods:
  NodePool()         - constructs pool and initializes free list
  int newNode()      - allocates node (returns index or NULL_VALUE)
  void deleteNode(i) - returns node index to free list
  Node* getPool()    - mutable access to pool array
  const Node* readPool() const - read-only access
  int getFree() const- returns head of free list
--------------------------------------------------------------------------*/

const int NULL_VALUE = -1;
const int NUM_NODES = 10;

typedef string ElementType;

struct Node {
    ElementType data;
    int next;

    Node();
    Node(const ElementType &d, int n = NULL_VALUE);
};

class NodePool {
public:
    NodePool();

    int newNode();
    void deleteNode(int index);

    Node* getPool();
    const Node* readPool() const;

    int getFree() const;

private:
    Node arr[NUM_NODES];
    int free;

    void initializePool();
};

#endif
