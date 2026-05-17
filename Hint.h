#ifndef HINT_H
#define HINT_H

#include <string>
using namespace std;

class Hint {
private:
    char type;
    string descrip;

public:
    Hint();
    Hint(char type);
    void setTipo(char type);
    char getTipo();
    void setDescrip(string descrip);
    string getDescrip();
    string getTypeName();
};

#endif
