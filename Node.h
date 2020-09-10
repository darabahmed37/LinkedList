//
// Created by darab on 10/9/20.
//

#ifndef DSA_COURSE_NODE_H
#define DSA_COURSE_NODE_H


template<class T>
class Node {
    T data;
    int index = 0;
public:
    int getIndex() const {
        return index;
    }

    void setIndex(int index) {
        Node::index = index;
    }

private:
    Node *next = nullptr;
public:


    T getData() const {
        return data;
    }

    void setData(T data) {
        Node::data = data;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }
};


#endif //DSA_COURSE_NODE_H
