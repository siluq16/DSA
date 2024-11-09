#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include "Node.h"
#include "Iterator.h"

using namespace std;

template <typename T>
class SingleList {
private:
    Node<T>* head;
    Node<T>* tail;
    int num;

public:
    SingleList() : head(nullptr), tail(nullptr), num(0) {}

    typedef Iterator<T> iterator;

    bool empty() const { return head == nullptr; }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
        num++;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        num++;
    }

    void pop_front() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        num--;
    }

    void pop_back() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        num--;
    }

    T front() const { return head ? head->data : T(); }
    T back() const { return tail ? tail->data : T(); }

    void sort() {
        if (!head) return;
        for (Node<T>* i = head; i->next; i = i->next) {
            for (Node<T>* j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void erase(const T& value) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;
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
                num--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }

    int size() const { return num; }
};

#endif
