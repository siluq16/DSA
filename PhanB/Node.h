#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T& d) : data(d), next(nullptr) {}

    T getData() { return data; }
    void setData(T& d) { data = d; }

    Node* getNext() { return next; }
    void setNext(Node* n) { next = n; }
};

#endif
