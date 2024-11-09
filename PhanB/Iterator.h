#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator {
private:
    Node<T>* nodePtr;

public:
    Iterator(Node<T>* ptr = nullptr) : nodePtr(ptr) {}

    T& operator*() { return nodePtr->data; }

    Iterator& operator++() {
        if (nodePtr) nodePtr = nodePtr->next;
        return *this;
    }

    bool operator!=(const Iterator& other) const { return nodePtr != other.nodePtr; }

    Node<T>* getcurr() const { return nodePtr; }  
};

#endif
