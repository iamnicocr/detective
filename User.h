#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class Location;

class User {
private:
    string name;
    int score;
    Location* posAct;

public:
    User();
    User(string name);
    void setName(string name);
    string getName();
    void setScore(int score);
    int getScore();
    void increScore();
    void halfScore();
    void doubScore();
    void restartScore();
    void setActPos(Location* posAct);
    Location* getActPos();
};

#endif
