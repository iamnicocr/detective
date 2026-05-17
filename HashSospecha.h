#ifndef HASHSOSPECHA_H
#define HASHSOSPECHA_H

#include "Sospechoso.h"
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using namespace std;

class HashSospecha {
private:
    static const int SIZE = 17;
    vector<list<pair<string, Sospechoso>>> table;
    int funcHas(string passw);

public:
    HashSospecha();
    void insert(Sospechoso sospechoso);
    bool exist(string name);
    Sospechoso* search(string name);
    void show();
};

#endif
