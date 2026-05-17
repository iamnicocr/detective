#include "City.h"
#include <cstdlib>
#include <ctime>

City::City() {
    start = nullptr;
    filas = 9;
    columnas = 9;
    srand(time(nullptr));
}

City::~City() {
    freeMemory();
}

void City::genBaseCity() {
    freeMemory();
    Location* prevRow = nullptr;

    for (int fila = 0; fila < filas; fila++) {
        Location* rowStart = nullptr;
        Location* prevLoc = nullptr;
        Location* upLoc = prevRow;

        for (int columna = 0; columna < columnas; columna++) {
            Location* newLoc = new Location(fila, columna);

            if (fila == 0 && columna == 0) {
                start = newLoc;
            }

            if (columna == 0) {
                rowStart = newLoc;
            }

            if (prevLoc != nullptr) {
                prevLoc->setRight(newLoc);
                newLoc->setLeft(prevLoc);
            }

            if (upLoc != nullptr) {
                upLoc->setDown(newLoc);
                newLoc->setUp(upLoc);
                upLoc = upLoc->getRight();
            }
            prevLoc = newLoc;
        }
        prevRow = rowStart;
    }
}

void City::freeMemory() {
    Location* row = start;

    while (row != nullptr) {
        Location* nextRow = row->getDown();
        Location* act = row;
        while (act != nullptr) {
            Location* next = act->getRight();
            delete act;
            act = next;
        }
        row = nextRow;
    }
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
    for (int i = 0; i < columnas + 2; i++) {
        cout << "# ";
    }
    cout << endl;
    Location* row = start;
    while (row != nullptr) {
        cout << "# ";
        Location* act = row;
        while (act != nullptr) {
            if (user.getActPos() == act) {
                cout << "D ";
            } else if (!act->getVisible()) {
                cout << "o ";
            } else {
                cout << act->getContent() << " ";
            }
            act = act->getRight();
        }
        cout << "#" << endl;
        row = row->getDown();
    }
    for (int i = 0; i < columnas + 2; i++) {
        cout << "# ";
    }
    cout << endl;
}

Location* City::getLocation(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        return nullptr;
    }
    Location* act = start;
    for (int i = 0; i < fila; i++) {
        act = act->getDown();
    }
    for (int j = 0; j < columna; j++) {
        act = act->getRight();
    }
    return act;
}

void City::genTestHints() {
    Location* loc1 = getLocation(1, 3);
    Location* loc2 = getLocation(3, 6);
    Location* loc3 = getLocation(6, 2);
    Location* loc4 = getLocation(7, 5);

    if (loc1 != nullptr && loc1->isFree() && !loc1->getVisita()) {
        loc1->setContent('H');
        loc1->setVisible(false);
    }
    if (loc2 != nullptr && loc2->isFree() && !loc2->getVisita()) {
        loc2->setContent('C');
        loc2->setVisible(false);
    }
    if (loc3 != nullptr && loc3->isFree() && !loc3->getVisita()) {
        loc3->setContent('T');
        loc3->setVisible(false);
    }
    if (loc4 != nullptr && loc4->isFree() && !loc4->getVisita()) {
        loc4->setContent('P');
        loc4->setVisible(false);
    }
}

Location* City::getRandFreeLoc() {
    if (start == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < 100; i++) {
        int fila = rand() % filas;
        int columna = rand() % columnas;

        Location* loc = getLocation(fila, columna);

        if (loc != nullptr && loc->isFree() && !loc->getVisita()) {
            return loc;
        }
    }
    Location* row = start;
    while (row != nullptr) {
        Location* act = row;
        while (act != nullptr) {
            if (act->isFree() && !act->getVisita()) {
                return act;
            }
            act = act->getRight();
        }
        row = row->getDown();
    }
    return nullptr;
}

void City::LocRandDetec(User& user) {
    Location* act = getLocation(4, 4);
    if (act != nullptr) {
        user.setActPos(act);
        act->setVisible(true);
        act->setVisita(true);
    }
}

void City::genAlleys() {
    int created = 0;
    int tries = 0;

    while (created < 16 && tries < 300) {
        Location* loc = getRandFreeLoc();

        if (loc != nullptr && loc->isFree() && !loc->getVisita()) {
            loc->setContent('|');
            loc->setVisible(false);
            created++;
        }
        tries++;
    }
    if (created < 16) {
        cout << "No se pudieron generar todos los callejones." << endl;
    }
}
