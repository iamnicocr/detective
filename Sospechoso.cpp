#include "Sospechoso.h"

Sospechoso::Sospechoso() {
    name = "";
    estatura = "";
    cabello = "";
    piel = "";
    nariz = "";
    genre = "";
    mano = "";
    acento = "";
    cicatriz = "";
    accesorio = "";
    calzado = "";
    olor = "";
    transporte = "";
    objeto = "";
    coartada = "";
    culpable = false;
}

Sospechoso::Sospechoso(string name, string estatura, string cabello, string piel, string nariz, string genre,
                       string mano, string acento, string cicatriz, string accesorio, string calzado,
                       string olor, string transporte, string objeto, string coartada) {
    this->name = name;
    this->estatura = estatura;
    this->cabello = cabello;
    this->piel = piel;
    this->nariz = nariz;
    this->genre = genre;
    this->mano = mano;
    this->acento = acento;
    this->cicatriz = cicatriz;
    this->accesorio = accesorio;
    this->calzado = calzado;
    this->olor = olor;
    this->transporte = transporte;
    this->objeto = objeto;
    this->coartada = coartada;
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

void Sospechoso::setMano(string mano) {
    this->mano = mano;
}

string Sospechoso::getMano() {
    return mano;
}

void Sospechoso::setAcento(string acento) {
    this->acento = acento;
}

string Sospechoso::getAcento() {
    return acento;
}

void Sospechoso::setCicatriz(string cicatriz) {
    this->cicatriz = cicatriz;
}

string Sospechoso::getCicatriz() {
    return cicatriz;
}

void Sospechoso::setAccesorio(string accesorio) {
    this->accesorio = accesorio;
}

string Sospechoso::getAccesorio() {
    return accesorio;
}

void Sospechoso::setCalzado(string calzado) {
    this->calzado = calzado;
}

string Sospechoso::getCalzado() {
    return calzado;
}

void Sospechoso::setOlor(string olor) {
    this->olor = olor;
}

string Sospechoso::getOlor() {
    return olor;
}

void Sospechoso::setTransporte(string transporte) {
    this->transporte = transporte;
}

string Sospechoso::getTransporte() {
    return transporte;
}

void Sospechoso::setObjeto(string objeto) {
    this->objeto = objeto;
}

string Sospechoso::getObjeto() {
    return objeto;
}

void Sospechoso::setCoartada(string coartada) {
    this->coartada = coartada;
}

string Sospechoso::getCoartada() {
    return coartada;
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
    atribs.push_back(mano);
    atribs.push_back(acento);
    atribs.push_back(cicatriz);
    atribs.push_back(accesorio);
    atribs.push_back(calzado);
    atribs.push_back(olor);
    atribs.push_back(transporte);
    atribs.push_back(objeto);
    atribs.push_back(coartada);
    return atribs;
}

void Sospechoso::show() {
    cout << name << " | "
         << estatura << ", "
         << cabello << ", "
         << piel << ", "
         << nariz << ", "
         << genre << ", "
         << mano << ", "
         << acento << ", "
         << cicatriz << ", "
         << accesorio << ", "
         << calzado << ", "
         << olor << ", "
         << transporte << ", "
         << objeto << ", "
         << coartada << endl;
}
