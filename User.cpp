#include "User.h"

User::User() {
    name = "";
    score = 0;
    posAct = nullptr;
}

User::User(string name) {
    this->name = name;
    score = 0;
    posAct = nullptr;
}

void User::setName(string name) {
    this->name = name;
}

string User::getName() {
    return name;
}

void User::setScore(int score) {
    this->score = score;
}

int User::getScore() {
    return score;
}

void User::increScore() {
    score++;
}

void User::halfScore() {
    score = score / 2;
}

void User::doubScore() {
    score = score * 2;
}

void User::restartScore() {
    score = 0;
}

void User::setActPos(Location* posAct) {
    this->posAct = posAct;
}

Location* User::getActPos() {
    return posAct;
}
