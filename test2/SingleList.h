#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
using namespace std;

template <typename T>
class SingleList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}

    void addLast(const T& value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    void remove(const T& value) {
        Node* current = head;
        Node* previous = nullptr;
        while (current) {
            if (current->data == value) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = previous;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    class Iterator {
    private:
        Node* nodePtr;

    public:
        Iterator(Node* ptr = nullptr) : nodePtr(ptr) {}

        T& operator*() { return nodePtr->data; }

        Iterator& operator++() {
            if (nodePtr) nodePtr = nodePtr->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const { return nodePtr != other.nodePtr; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    // Thêm phương thức begin và end const
    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

#endif
