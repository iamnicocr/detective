#ifndef HINTSTACK_H
#define HINTSTACK_H

#include "Hint.h"
#include <iostream>
using namespace std;

class HintNode {
private:
    Hint dato;
    HintNode* next;

public:
    HintNode(Hint dato);
    Hint getDato();
    void setDato(Hint dato);
    HintNode* getNext();
    void setNext(HintNode* next);
};

class HintStack {
private:
    HintNode* topNode;
    int cantidad;

public:
    HintStack();
    ~HintStack();
    bool isEmpty();
    int getAmnt();
    void push(Hint hint);
    Hint pop();
    Hint top();
    void show();
    void clean();
};

#endif
