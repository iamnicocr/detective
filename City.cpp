#include "City.h"

City::City() {
    start = nullptr;
    filas = 9;
    columnas = 9;
}

City::~City() {
    freeMemory();
}

void City::genBaseCity() {
    /*
     * Método creado para que la ciudad exista como entidad principal
     * construir lista múltiplemente enlazada de 9x9 nodos
     */
}

void City::freeMemory() {
    /*
     * Recorrido para liberar los nodos creados
     */
    start = nullptr;
}

Location* City::getStart() {
    return start;
}

int City::getFilas() {
    return filas;
}

int City::getColumnas() {
    return columnas;
}

void City::printCity(User& user) {
    cout << endl;
    cout << user.getName() << ", tu puntaje actual es: " << user.getScore() << endl;

    /*
     * Imprimir recorriendo la lista múltiplemente enlazada
     */
    for (int i = 0; i < columnas + 2; i++) {
        cout << "# ";
    }
    cout << endl;

    for (int i = 0; i < filas; i++) {
        cout << "# ";
        for (int j = 0; j < columnas; j++) {
            cout << "o ";
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < columnas + 2; i++) {
        cout << "# ";
    }
    cout << endl;
}

Location* City::getLocation(int fila, int columna) {
    return nullptr;
}

Location* City::getRandFreeLoc() {
    return nullptr;
}

void City::LocRandDetec(User& user) {
    user.setActPos(nullptr);
}
