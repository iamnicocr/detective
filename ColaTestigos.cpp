#include "ColaTestigos.h"

NodoTestigo::NodoTestigo(Testigo dato) {
    this->dato = dato;
    next = nullptr;
}

Testigo NodoTestigo::getDato() {
    return dato;
}

void NodoTestigo::setDato(Testigo dato) {
    this->dato = dato;
}

NodoTestigo* NodoTestigo::getNext() {
    return next;
}

void NodoTestigo::setNext(NodoTestigo* next) {
    this->next = next;
}

ColaTestigos::ColaTestigos() {
    frente = nullptr;
    end = nullptr;
    cantidad = 0;
}

ColaTestigos::~ColaTestigos() {
    clean();
}

bool ColaTestigos::isEmpty() {
    return frente == nullptr;
}

int ColaTestigos::getAmnt() {
    return cantidad;
}

void ColaTestigos::enqueue(Testigo testigo) {
    NodoTestigo* newNode = new NodoTestigo(testigo);
    if (isEmpty()) {
        frente = newNode;
        end = newNode;
    } else {
        end->setNext(newNode);
        end = newNode;
    }
    cantidad++;
}

Testigo ColaTestigos::dequeue() {
    if (isEmpty()) {
        return Testigo();
    }

    NodoTestigo* aux = frente;
    Testigo testigo = aux->getDato();

    frente = frente->getNext();

    if (frente == nullptr) {
        end = nullptr;
    }

    delete aux;
    cantidad--;

    return testigo;
}

Testigo ColaTestigos::front() {
    if (isEmpty()) {
        return Testigo();
    }

    return frente->getDato();
}

void ColaTestigos::showAmont() {
    cout << "Declaraciones pendientes en cola: " << cantidad << endl;
}

void ColaTestigos::clean() {
    while (!isEmpty()) {
        dequeue();
    }
}
