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
#include <vector>
using namespace std;

class Game {
private:
    User detective;
    City city;
    HintStack hintStack;
    HashSospecha tablaSospecha;
    ColaTestigos colaTestigo;
    ABBScores scoreTree;
    vector<string> faultAtribs;
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
    void showSospechosos();
    void printStructs();
    void moveDetec(char opc);
    bool isHint(char content);
    void collectHint(Location* loc);
    void useHint();
    int hintsFound;
    void loadSospechosos();
    bool isAtribRevealed(string atrib);
    void revealFaultAtrib();
    bool isWitness(char content);
    void collectWitness(Location* loc);
    void interrogWitness();
    bool accusPhase;
    void startAccusation();
    void saveFinalScore();
    void searchDetecScore();

public:
    Game();
    void ejecutar();
};

#endif
