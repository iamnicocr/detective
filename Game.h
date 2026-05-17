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
    void playLoop();
    void printControls();
    void printTitle();
    void printMenu();
    void registerDetec();
    void startGame();
    void printScores();
    void printStructs();


public:
    Game();
    void ejecutar();
};

#endif
