//
// Created by darab on 10/9/20.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;
int main(){
LinkedList<int>*linkedList=new LinkedList<int>;

    for (int i = 0; i < 5; ++i) {
        linkedList->add(i);
    }
linkedList->remove(1);
linkedList->displayAll();
}