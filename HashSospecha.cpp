#include "HashSospecha.h"

HashSospecha::HashSospecha() {
    table.resize(SIZE);
}

int HashSospecha::funcHas(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

int HashSospecha::getPosc(string key) {
    return funcHas(key);
}

void HashSospecha::insert(Sospechoso sospechoso) {
    string key = sospechoso.getName();
    int posc = funcHas(key);
    for (auto& par : table[posc]) {
        if (par.first == key) {
            cout << "El sospechoso " << key << " ya existe en la tabla." << endl;
            return;
        }
    }
    table[posc].push_back(make_pair(key, sospechoso));
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
