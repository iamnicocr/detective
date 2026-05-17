#include "Sospechoso.h"

Sospechoso::Sospechoso() {
    name = "";
    estatura = "";
    cabello = "";
    piel = "";
    nariz = "";
    genre = "";
    culpable = false;
}

Sospechoso::Sospechoso(string name, string estatura, string cabello, string piel, string nariz, string genre) {
    this->name = name;
    this->estatura = estatura;
    this->cabello = cabello;
    this->piel = piel;
    this->nariz = nariz;
    this->genre = genre;
    culpable = false;
}

void Sospechoso::setName(string name) {
    this->name = name;
}

string Sospechoso::getName() {
    return name;
}

void Sospechoso::setStatur(string estatura) {
    this->estatura = estatura;
}

string Sospechoso::getStatur() {
    return estatura;
}

void Sospechoso::setHair(string cabello) {
    this->cabello = cabello;
}

string Sospechoso::getHair() {
    return cabello;
}

void Sospechoso::setPiel(string piel) {
    this->piel = piel;
}

string Sospechoso::getPiel() {
    return piel;
}

void Sospechoso::setNose(string nariz) {
    this->nariz = nariz;
}

string Sospechoso::getNose() {
    return nariz;
}

void Sospechoso::setGenre(string genre) {
    this->genre = genre;
}

string Sospechoso::getGenre() {
    return genre;
}

void Sospechoso::setFault(bool culpable) {
    this->culpable = culpable;
}

bool Sospechoso::getFault() {
    return culpable;
}

vector<string> Sospechoso::getAtribs() {
    vector<string> atribs;
    atribs.push_back(estatura);
    atribs.push_back(cabello);
    atribs.push_back(piel);
    atribs.push_back(nariz);
    atribs.push_back(genre);
    return atribs;
}

void Sospechoso::show() {
    cout << name << " | "
    << estatura << ", "
    << cabello << ", "
    << piel << ", "
    << nariz << ", "
    << genre << endl;
}
