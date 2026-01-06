#include "nodePool.h"
#include <iostream>
using namespace std;

/* Node constructors */

Node::Node() : data(""), next(NULL_VALUE) {}

Node::Node(const ElementType &d, int n) : data(d), next(n) {}

/* NodePool Implementation */

NodePool::NodePool() {
    initializePool();
}

void NodePool::initializePool() {
    for (int i = 0; i < NUM_NODES - 1; ++i) {
        arr[i].next = i + 1;
        arr[i].data = "";
    }
    arr[NUM_NODES - 1].next = NULL_VALUE;
    arr[NUM_NODES - 1].data = "";
    free = 0;
}

int NodePool::newNode() {
    if (free == NULL_VALUE) {
        cerr << "NodePool::newNode() - no available nodes\n";
        return NULL_VALUE;
    }

    int index = free;
    free = arr[free].next;
    arr[index].next = NULL_VALUE;
    arr[index].data = "";

    return index;
}

void NodePool::deleteNode(int index) {
    if (index < 0 || index >= NUM_NODES) {
        cerr << "NodePool::deleteNode() - index out of range\n";
        return;
    }
    arr[index].next = free;
    arr[index].data = "";
    free = index;
}

Node* NodePool::getPool() {
    return arr;
}

const Node* NodePool::readPool() const {
    return arr;
}

int NodePool::getFree() const {
    return free;
}
