#ifndef GAME_H
#define GAME_H

#include "User.h"
#include "City.h"
#include "HintStack.h"
#include "HashSospecha.h"
#include "ColaTestigos.h"
#include "ABBScores.h"
#include <iostream>
#include <string>
using namespace std;

class Game {
private:
    User detective;
    City city;
    HintStack hintStack;
    HashSospecha tablaSospecha;
    ColaTestigos colaTestigo;
    ABBScores scoreTree;
    bool activeGame;
    string faultName;
    void setRandomFault();
    void playLoop();
    void printControls();
    void printTitle();
    void printMenu();
    void registerDetec();
    void startGame();
    void printScores();
    void printStructs();
    void moveDetec(char opc);
    bool isHint(char content);
    void collectHint(Location* loc);
    void useHint();
    int hintsFound;
    void loadSospechosos();

public:
    Game();
    void ejecutar();
};

#endif
