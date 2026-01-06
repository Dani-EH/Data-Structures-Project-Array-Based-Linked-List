#include "ArrayBasedList.h"
#include <iostream>
using namespace std;

ArrayBasedList::ArrayBasedList() : first(NULL_VALUE), pool() {}

ArrayBasedList::ArrayBasedList(const ArrayBasedList &other) : first(NULL_VALUE), pool() {
    int otherPtr = other.first;
    int lastNew = NULL_VALUE;

    while (otherPtr != NULL_VALUE) {
        int newIdx = pool.newNode();
        if (newIdx == NULL_VALUE) {
            cerr << "Error: Pool exhausted during copy.\n";
            return;
        }

        pool.getPool()[newIdx].data = other.pool.readPool()[otherPtr].data;

        if (lastNew == NULL_VALUE)
            first = newIdx;
        else
            pool.getPool()[lastNew].next = newIdx;

        lastNew = newIdx;
        otherPtr = other.pool.readPool()[otherPtr].next;
    }
}

ArrayBasedList& ArrayBasedList::operator=(const ArrayBasedList &other) {
    if (this != &other) {
        while (!isEmpty())
            remove(0);

        int otherPtr = other.first;
        int lastNew = NULL_VALUE;

        while (otherPtr != NULL_VALUE) {
            int newIdx = pool.newNode();
            if (newIdx == NULL_VALUE) {
                cerr << "Error: Pool exhausted during assignment.\n";
                break;
            }

            pool.getPool()[newIdx].data = other.pool.readPool()[otherPtr].data;

            if (lastNew == NULL_VALUE)
                first = newIdx;
            else
                pool.getPool()[lastNew].next = newIdx;

            lastNew = newIdx;
            otherPtr = other.pool.readPool()[otherPtr].next;
        }
    }
    return *this;
}

ArrayBasedList::~ArrayBasedList() {
    while (!isEmpty())
        remove(0);
}

bool ArrayBasedList::isEmpty() const {
    return first == NULL_VALUE;
}

int ArrayBasedList::getNodeAt(int position) const {
    int ptr = first;
    int count = 0;

    while (ptr != NULL_VALUE && count < position) {
        ptr = pool.readPool()[ptr].next;
        count++;
    }
    return ptr;
}

void ArrayBasedList::insert(int position, const ElementType &item) {
    if (position < 0) {
        cout << "Invalid position.\n";
        return;
    }

    int newIdx = pool.newNode();
    if (newIdx == NULL_VALUE) {
        cout << "No free nodes available.\n";
        return;
    }

    pool.getPool()[newIdx].data = item;

    if (position == 0 || first == NULL_VALUE) {
        pool.getPool()[newIdx].next = first;
        first = newIdx;
        return;
    }

    int prev = getNodeAt(position - 1);
    if (prev == NULL_VALUE) {
        cout << "Invalid position.\n";
        pool.deleteNode(newIdx);
        return;
    }

    pool.getPool()[newIdx].next = pool.getPool()[prev].next;
    pool.getPool()[prev].next = newIdx;
}

void ArrayBasedList::remove(int position) {
    if (isEmpty()) {
        cout << "List is empty.\n";
        return;
    }

    if (position == 0) {
        int old = first;
        first = pool.getPool()[old].next;
        pool.deleteNode(old);
        return;
    }

    int prev = getNodeAt(position - 1);
    if (prev == NULL_VALUE) {
        cout << "Invalid position.\n";
        return;
    }

    int curr = pool.getPool()[prev].next;
    if (curr == NULL_VALUE) {
        cout << "Invalid position.\n";
        return;
    }

    pool.getPool()[prev].next = pool.getPool()[curr].next;
    pool.deleteNode(curr);
}

int ArrayBasedList::search(const ElementType &item) const {
    int ptr = first;
    int pos = 0;

    while (ptr != NULL_VALUE) {
        if (pool.readPool()[ptr].data == item)
            return pos;

        ptr = pool.readPool()[ptr].next;
        pos++;
    }
    return -1;
}

void ArrayBasedList::display() const {
    int ptr = first;
    cout << "List: [ ";
    while (ptr != NULL_VALUE) {
        cout << pool.readPool()[ptr].data << " ";
        ptr = pool.readPool()[ptr].next;
    }
    cout << "]\n";
}

int ArrayBasedList::size() const {
    int count = 0;
    int ptr = first;

    while (ptr != NULL_VALUE) {
        count++;
        ptr = pool.readPool()[ptr].next;
    }
    return count;
}

int ArrayBasedList::getFree() const {
    return pool.getFree();
}
