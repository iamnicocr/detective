#include "Hint.h"

Hint::Hint() {
    type = ' ';
    descrip = "";
}

Hint::Hint(char type) {
    this->type = type;
    descrip = getTypeName();
}

void Hint::setTipo(char type) {
    this->type = type;
    descrip = getTypeName();
}

char Hint::getTipo() {
    return type;
}

void Hint::setDescrip(string descrip) {
    this->descrip = descrip;
}

string Hint::getDescrip() {
    return descrip;
}

string Hint::getTypeName() {
    if (type == 'H') {
        return "Huella";
    }
    if (type == 'C') {
        return "Coartada";
    }
    if (type == 'T') {
        return "Testimonio";
    }
    if (type == 'P') {
        return "Prueba forense";
    }
    return "Sin pista";
}
