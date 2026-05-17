#ifndef TESTIGO_H
#define TESTIGO_H

#include <string>
using namespace std;

class Testigo {
private:
    string name;
    string declaracion;
    bool interrogado;

public:
    Testigo();
    Testigo(string name, string declaracion);
    void setName(string name);
    string getName();
    void setDeclar(string declaracion);
    string getDeclar();
    void setInterrog(bool interrogado);
    bool getInterrog();
};

#endif
