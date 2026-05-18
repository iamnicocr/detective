#include "Game.h"
#include <cstdlib>

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
    city.genTestHints();
    city.genAlleys();
    printStructs();
    cout << endl;
    cout << "Vista inicial del tablero:" << endl;
    city.printCity(detective);
    playLoop();
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

void Game::moveDetec(char opc) {
    Location* act = detective.getActPos();
    Location* next = nullptr;
    detective.increScore();

    if (act == nullptr) {
        cout << "El detective aun no tiene ubicacion." << endl;
        return;
    }
    if (opc == 'W') {
        next = act->getUp();
    } else if (opc == 'A') {
        next = act->getLeft();
    } else if (opc == 'S') {
        next = act->getDown();
    } else if (opc == 'D') {
        next = act->getRight();
    }
    if (next == nullptr) {
        cout << "No puedes salir de la ciudad." << endl;
        return;
    }
    if (next->getContent() == '|') {
        next->setVisible(true);
        cout << "No puedes pasar. Hay un callejon cerrado." << endl;
        return;
    }
    detective.setActPos(next);
    next->setVisible(true);
    next->setVisita(true);
    collectHint(next);
}
void Game::printControls() {
    cout << endl;
    cout << "Controles disponibles:" << endl;
    cout << "W/A/S/D -> mover detective" << endl;
    cout << "T -> ver pistas recogidas" << endl;
    cout << "X -> usar pista" << endl;
    cout << "S -> ver sospechosos" << endl;
    cout << "I -> interrogar testigo " << endl;
    cout << "Q -> salir de la partida" << endl;
}

bool Game::isHint(char content) {
    return content == 'H' || content == 'C' || content == 'T' || content == 'P';
}

void Game::collectHint(Location* loc) {
    if (loc == nullptr) {
        return;
    }
    char type = loc->getContent();
    if (!isHint(type)) {
        return;
    }
    Hint hint(type);
    hintStack.push(hint);
    cout << "Has recogido una pista: " << hint.getTypeName() << " (" << type << ")" << endl;
    loc->setContent(' ');
    loc->setVisible(true);
    loc->setVisita(true);
}

void Game::useHint() {
    if (hintStack.isEmpty()) {
        cout << "No tienes pistas para usar." << endl;
        return;
    }
    Hint hint = hintStack.pop();
    char type = hint.getTipo();
    cout << "Usaste la ultima pista recogida: "<< hint.getTypeName()<< " (" << type << ")" << endl;
    if (type == 'H') {
        int prevScore = detective.getScore();
        detective.halfScore();
        cout << "La Huella redujo tu puntaje a la mitad." << endl;
        cout << "Puntaje anterior: " << prevScore << endl;
        cout << "Puntaje actual: " << detective.getScore() << endl;
    } else if (type == 'C') {
        city.removeRandAlleys(2);
    } else if (type == 'T') {
        int prevScore = detective.getScore();
        int result = rand() % 2;
        if (result == 0) {
            detective.restartScore();
            cout << "El Testimonio fue favorable. Tu puntaje bajo a cero." << endl;
        } else {
            detective.doubScore();
            cout << "El Testimonio fue confuso. Tu puntaje se duplico." << endl;
        }
        cout << "Puntaje anterior: " << prevScore << endl;
        cout << "Puntaje actual: " << detective.getScore() << endl;
    } else {
        cout << "El efecto de esta pista se implementara en otro avance." << endl;
    }
}

void Game::playLoop() {
    char opc;
    bool playing = true;
    while (playing) {
        printControls();
        cout << endl;
        cout << "Ingrese una accion: ";
        cin >> opc;
        if (opc == 'Q') {
            cout << "Saliendo de la partida actual..." << endl;
            playing = false;
        } else if (opc == 'W' || opc == 'A' || opc == 'S' || opc == 'D') {
            moveDetec(opc);
            city.printCity(detective);
        } else if (opc == 'T') {
            hintStack.show();
            city.printCity(detective);
        } else if (opc == 'X') {
            useHint();
            city.printCity(detective);
        } else if (opc == 'S') {
            cout << "Consulta de sospechosos pendiente." << endl;
            city.printCity(detective);
        } else if (opc == 'I') {
            cout << "Interrogatorio pendiente." << endl;
            city.printCity(detective);
        } else {
            cout << "Accion invalida." << endl;
            city.printCity(detective);
        }
    }
}