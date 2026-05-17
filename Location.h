#ifndef LOCATION_H
#define LOCATION_H

class Location {
private:
    int fila;
    int columna;
    char content;
    bool visible;
    bool visitada;
    Location* up;
    Location* down;
    Location* left;
    Location* right;

public:
    Location();
    Location(int fila, int columna);
    void setFila(int fila);
    int getFila();
    void setColumna(int columna);
    int getColumna();
    void setContent(char content);
    char getContent();
    void setVisible(bool visible);
    bool getVisible();
    void setVisita(bool visitada);
    bool getVisita();
    void setUp(Location* up);
    Location* getUp();
    void setDown(Location* down);
    Location* getDown();
    void setLeft(Location* left);
    Location* getLeft();
    void setRight(Location* right);
    Location* getRight();
    bool isFree();
};

#endif
