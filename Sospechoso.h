#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Sospechoso {
private:
    string name;
    string estatura;
    string cabello;
    string piel;
    string nariz;
    string genre;
    bool culpable;

public:
    Sospechoso();
    Sospechoso(string name, string estatura, string cabello, string piel, string nariz, string genre);
    void setName(string name);
    string getName();
    void setStatur(string estatura);
    string getStatur();
    void setHair(string cabello);
    string getHair();
    void setPiel(string piel);
    string getPiel();
    void setNose(string nariz);
    string getNose();
    void setGenre(string genre);
    string getGenre();
    void setFault(bool culpable);
    bool getFault();
    vector<string> getAtribs();
    void show();
};

#endif
