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

Location* City::getRandFreeLoc() {
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

void City::genTestAlleys() {
    Location* loc1 = getLocation(1, 1);
    Location* loc2 = getLocation(2, 6);
    Location* loc3 = getLocation(5, 3);
    Location* loc4 = getLocation(7, 7);
    if (loc1 != nullptr) {
        loc1->setContent('|');
        loc1->setVisible(true);
    }
    if (loc2 != nullptr) {
        loc2->setContent('|');
        loc2->setVisible(true);
    }
    if (loc3 != nullptr) {
        loc3->setContent('|');
        loc3->setVisible(true);
    }
    if (loc4 != nullptr) {
        loc4->setContent('|');
        loc4->setVisible(true);
    }
}
