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
    string mano;
    string acento;
    string cicatriz;
    string accesorio;
    string calzado;
    string olor;
    string transporte;
    string objeto;
    string coartada;
    bool culpable;

public:
    Sospechoso();
    Sospechoso(string name, string estatura, string cabello, string piel, string nariz, string genre,
               string mano, string acento, string cicatriz, string accesorio, string calzado,
               string olor, string transporte, string objeto, string coartada);

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
    void setMano(string mano);
    string getMano();
    void setAcento(string acento);
    string getAcento();
    void setCicatriz(string cicatriz);
    string getCicatriz();
    void setAccesorio(string accesorio);
    string getAccesorio();
    void setCalzado(string calzado);
    string getCalzado();
    void setOlor(string olor);
    string getOlor();
    void setTransporte(string transporte);
    string getTransporte();
    void setObjeto(string objeto);
    string getObjeto();
    void setCoartada(string coartada);
    string getCoartada();
    void setFault(bool culpable);
    bool getFault();
    vector<string> getAtribs();
    void show();
};

#endif
