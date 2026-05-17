#include "Testigo.h"

Testigo::Testigo() {
    name = "";
    declaracion = "";
    interrogado = false;
}

Testigo::Testigo(string name, string declaracion) {
    this->name = name;
    this->declaracion = declaracion;
    interrogado = false;
}

void Testigo::setName(string name) {
    this->name = name;
}

string Testigo::getName() {
    return name;
}

void Testigo::setDeclar(string declaracion) {
    this->declaracion = declaracion;
}

string Testigo::getDeclar() {
    return declaracion;
}

void Testigo::setInterrog(bool interrogado) {
    this->interrogado = interrogado;
}

bool Testigo::getInterrog() {
    return interrogado;
}
