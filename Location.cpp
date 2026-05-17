#include "Location.h"

Location::Location() {
    fila = 0;
    columna = 0;
    content = ' ';
    visible = false;
    visitada = false;
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

Location::Location(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    content = ' ';
    visible = false;
    visitada = false;
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

void Location::setFila(int fila) {
    this->fila = fila;
}

int Location::getFila() {
    return fila;
}

void Location::setColumna(int columna) {
    this->columna = columna;
}

int Location::getColumna() {
    return columna;
}

void Location::setContent(char content) {
    this->content = content;
}

char Location::getContent() {
    return content;
}

void Location::setVisible(bool visible) {
    this->visible = visible;
}

bool Location::getVisible() {
    return visible;
}

void Location::setVisita(bool visitada) {
    this->visitada = visitada;
}

bool Location::getVisita() {
    return visitada;
}

void Location::setUp(Location* up) {
    this->up = up;
}

Location* Location::getUp() {
    return up;
}

void Location::setDown(Location* down) {
    this->down = down;
}

Location* Location::getDown() {
    return down;
}

void Location::setLeft(Location* left) {
    this->left = left;
}

Location* Location::getLeft() {
    return left;
}

void Location::setRight(Location* right) {
    this->right = right;
}

Location* Location::getRight() {
    return right;
}

bool Location::isFree() {
    return content == ' ';
}
