#ifndef ABBSCORES_H
#define ABBSCORES_H

#include <string>
#include <iostream>
using namespace std;

class ScoreNode {
private:
    string nameDetective;
    int score;
    ScoreNode* left;
    ScoreNode* right;

public:
    ScoreNode(string nameDetective, int score);
    string getDetecName();
    void setDetecName(string nameDetective);
    int getScore();
    void setScore(int score);
    ScoreNode* getLeft();
    void setLeft(ScoreNode* left);
    ScoreNode* getRight();
    void setRight(ScoreNode* right);
};

class ABBScores {
private:
    ScoreNode* root;
    ScoreNode* recursInsert(ScoreNode* act, string nameDetective, int score);
    ScoreNode* searchRecurs(ScoreNode* act, string nameDetective);
    void printRecursOrd(ScoreNode* act);
    void freeRecurs(ScoreNode* act);

public:
    ABBScores();
    ~ABBScores();
    void insert(string nameDetective, int score);
    ScoreNode* search(string nameDetective);
    void printOrdered();
};

#endif
