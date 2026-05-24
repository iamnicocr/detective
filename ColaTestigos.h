#ifndef COLATESTIGOS_H
#define COLATESTIGOS_H

#include "Testigo.h"
#include <iostream>
using namespace std;

class NodoTestigo {
private:
    Testigo dato;
    NodoTestigo* next;

public:
    NodoTestigo(Testigo dato);
    Testigo getDato();
    void setDato(Testigo dato);
    NodoTestigo* getNext();
    void setNext(NodoTestigo* next);
};

class ColaTestigos {
private:
    NodoTestigo* frente;
    NodoTestigo* end;
    int cantidad;

public:
    ColaTestigos();
    ~ColaTestigos();
    bool isEmpty();
    int getAmnt();
    void enqueue(Testigo testigo);
    Testigo dequeue();
    Testigo front();
    void showAmont();
    void clean();
};

#endif
