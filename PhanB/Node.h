#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& d) : data(d), next(nullptr) {}

    T getData() const { return data; }
    void setData(const T& d) { data = d; }

    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
};

#endif
