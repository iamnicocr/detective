#include "HashSospecha.h"

HashSospecha::HashSospecha() {
    table.resize(SIZE);
}

int HashSospecha::funcHas(string passw) {
    int sum = 0;
    for (int i = 0; i < passw.length(); i++) {
        sum += passw[i];
    }
    return sum % SIZE;
}

void HashSospecha::insert(Sospechoso sospechoso) {
    string passw = sospechoso.getName();
    int posc = funcHas(passw);
    for (auto& par : table[posc]) {
        if (par.first == passw) {
            cout << "El sospechoso " << passw << " ya existe en la tabla." << endl;
            return;
        }
    }
    table[posc].push_back(make_pair(passw, sospechoso));
}

bool HashSospecha::exist(string name) {
    return search(name) != nullptr;
}

Sospechoso* HashSospecha::search(string name) {
    int posc = funcHas(name);
    for (auto& par : table[posc]) {
        if (par.first == name) {
            return &par.second;
        }
    }
    return nullptr;
}

void HashSospecha::show() {
    cout << "Tabla Hash de sospechosos:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Posicion " << i << ": ";

        if (table[i].empty()) {
            cout << "vacia";
        } else {
            for (auto& par : table[i]) {
                cout << "[" << par.first << "] ";
            }
        }
        cout << endl;
    }
}
