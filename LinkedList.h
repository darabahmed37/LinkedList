#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class LinkedList {
private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    int index = 0;
    Node<T> getObject(int index) {
        if (index >= LinkedList::index) {
            cerr << "Index out Of Bound jani";
            return nullptr;
        }
        static Node<T> *temp = first;
        if (temp != nullptr) {
            if (temp->getIndex() == index)
                return temp;
        }
        temp = temp->getNext();
        get(index);
    }

    void addFirst(T data) {
        first = new Node<T>;
        first->setData(data);
        last = first;
        first->setIndex(index++);
    }

    void re_index_After_DELETEING(int index, Node<T> *temp) {
        while (temp != nullptr) {
            temp->setIndex(index++);
            temp = (temp->getNext());
        }
    }

public:
    bool add(T data) {

        if (first == nullptr) {
            addFirst(data);
        } else {
            last->setNext(new Node<T>);
            last = last->getNext();
            last->setData(data);
            last->setIndex(index++);
            return true;
        }
        return false;
    }

    void displayAll() {

        static Node<T> *temp = first;
        if (temp != nullptr) {
            cout << temp->getData() << " index is at " << temp->getIndex() << endl;
            temp = temp->getNext();

            displayAll();

        }

    }

    T get(int index) {
        if (index >= LinkedList::index) {
            cerr << "Index out Of Bound jani";
            return 0;
        }
        static Node<T> *temp = first;
        if (temp != nullptr) {
            if (temp->getIndex() == index)
                return temp->getData();
        }
        temp = temp->getNext();
        get(index);
    }


    void remove(int index) {
        Node<T> *before = first;
        Node<T> *after = before->getNext();
        while (after != nullptr) {
            if (after->getIndex() == index) {
                before->setNext(after->getNext());
                re_index_After_DELETEING(index, after->getNext());

                return;
            }
            before = after;
            after = after->getNext();
        }
    }

    void concatenate(LinkedList<T> *linkedList) {
        Node<T>*temp=linkedList->first;
        int in=last->getIndex();
        temp->setIndex(in++);
        last->setNext(temp);

        while (temp!= nullptr){
            temp->setIndex(in++);
            temp=temp->getNext();


        }

    }
};