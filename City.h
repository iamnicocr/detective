#ifndef CITY_H
#define CITY_H

#include "Location.h"
#include "User.h"
#include <iostream>
using namespace std;

class City {
private:
    Location* start;
    int filas;
    int columnas;

public:
    City();
    ~City();
    void genBaseCity();
    void freeMemory();
    Location* getStart();
    int getFilas();
    int getColumnas();
    void printCity(User& user);
    Location* getLocation(int fila, int columna);
    Location* getRandFreeLoc();
    void LocRandDetec(User& user);
    void genAlleys();
    void genTestHints();
    void removeRandAlleys(int amnt);
    void relocHint(char type);
    void hideMap(Location* posAct);
};

#endif
