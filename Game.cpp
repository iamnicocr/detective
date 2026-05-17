#include "Game.h"

Game::Game() {
    activeGame = true;
}

void Game::ejecutar() {
    int opc;

    printTitle();

    while (activeGame) {
        printMenu();
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                registerDetec();
                startGame();
                break;

            case 2:
                printScores();
                break;

            case 3:
                cout << "Saliendo del sistema del detective..." << endl;
                activeGame = false;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    }
}

void Game::printTitle() {
    cout << "==========================================" << endl;
    cout << "        EL CASO DEL DETECTIVE" << endl;
    cout << "==========================================" << endl;
    cout << "Proyecto final de Estructuras de Datos 20261" << endl;
    cout << "Realizado por Nicolas Carrillo" << endl;
    cout << "==========================================" << endl;
}

void Game::printMenu() {
    cout << endl;
    cout << "--------------- MENU PRINCIPAL -----------" << endl;
    cout << "1. Iniciar juego" << endl;
    cout << "2. Ver puntajes historicos" << endl;
    cout << "3. Salir" << endl;
    cout << "------------------------------------------" << endl;
}

void Game::registerDetec() {
    string name;

    cout << endl;
    cout << "Ingrese el nombre del detective: ";
    cin >> name;

    detective = User(name);
}

void Game::startGame() {
    cout << endl;
    cout << "Preparando caso para " << detective.getName() << "..." << endl;
    city.genBaseCity();
    city.LocRandDetec(detective);
    printStructs();
    cout << endl;
    cout << "Vista preliminar del tablero:" << endl;
    city.printCity(detective);
    cout << endl;
}

void Game::printScores() {
    cout << endl;
    scoreTree.printOrdered();
}

void Game::printStructs() {
    cout << endl;
    cout << "Estructuras preparadas para el proyecto:" << endl;
    cout << "- City: lista multiple enlazada de ubicaciones" << endl;
    cout << "- HintStack: ultima pista recogida sera la primera disponible" << endl;
    cout << "- HashSospecha: sospechosos buscados por nombre" << endl;
    cout << "- ColaTestigos: declaraciones en orden de llegada" << endl;
    cout << "- ABBScores: historico ordenado de menor a mayor" << endl;
}
