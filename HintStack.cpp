#include "HintStack.h"

HintNode::HintNode(Hint dato) {
    this->dato = dato;
    next = nullptr;
}

Hint HintNode::getDato() {
    return dato;
}

void HintNode::setDato(Hint dato) {
    this->dato = dato;
}

HintNode* HintNode::getNext() {
    return next;
}

void HintNode::setNext(HintNode* next) {
    this->next = next;
}

HintStack::HintStack() {
    topNode = nullptr;
    cantidad = 0;
}

HintStack::~HintStack() {
    clean();
}

bool HintStack::isEmpty() {
    return topNode == nullptr;
}

int HintStack::getAmnt() {
    return cantidad;
}

void HintStack::push(Hint hint) {
    HintNode* newNode = new HintNode(hint);
    newNode->setNext(topNode);
    topNode = newNode;
    cantidad++;
}

Hint HintStack::pop() {
    if (isEmpty()) {
        return Hint();
    }
    HintNode* aux = topNode;
    Hint hint = aux->getDato();
    topNode = topNode->getNext();
    delete aux;
    cantidad--;
    return hint;
}

Hint HintStack::top() {
    if (isEmpty()) {
        return Hint();
    }
    return topNode->getDato();
}

void HintStack::show() {
    if (isEmpty()) {
        cout << "Aun no hay pistas recogidas." << endl;
        return;
    }
    HintNode* act = topNode;
    int posc = 0;
    cout << "Pistas recogidas:" << endl;
    while (act != nullptr) {
        cout << "[ " << act->getDato().getTipo() << " ]";
        if (posc == 0) {
            cout << " <- ultima pista disponible";
        }
        cout << endl;
        act = act->getNext();
        posc++;
    }
}

void HintStack::clean() {
    while (!isEmpty()) {
        pop();
    }
}
