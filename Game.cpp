#include "Game.h"
#include <cstdlib>
#include <cctype>

Game::Game() {
    activeGame = true;
    accusPhase = false;
    hintsFound = 0;
    faultName = "";
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
                searchDetecScore();
                break;
            case 4:
                cout << "Saliendo del sistema del detective..." << endl;
                activeGame = false;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    }
}

void Game::searchDetecScore() {
    string name;
    cout << "Ingrese el nombre del detective a buscar: ";
    cin >> name;
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);
    }
    if (!name.empty()) {
        name[0] = toupper(name[0]);
    }
    ScoreNode* found = scoreTree.search(name);
    if (found == nullptr) {
        cout << name << " aun no tiene partidas registradas." << endl;
        return;
    }
    cout << "Detective encontrado en ABBScores." << endl;
    cout << "Nombre: " << found->getDetecName() << endl;
    cout << "Mejor score: " << found->getScore() << " puntos." << endl;
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
    cout << "3. Buscar detective por nombre" << endl;
    cout << "4. Salir" << endl;
    cout << "------------------------------------------" << endl;
}

void Game::registerDetec() {
    string name;
    cout << "Ingrese el nombre del detective: ";
    cin >> name;
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);
    }
    if (!name.empty()) {
        name[0] = toupper(name[0]);
    }
    detective = User(name);
}

void Game::startGame() {
    cout << "Preparando caso para " << detective.getName() << "..." << endl;
    hintsFound = 0;
    accusPhase = false;
    faultName = "";
    faultAtribs.clear();
    hintStack.clean();
    colaTestigo.clean();
    loadSospechosos();
    setRandomFault();
    city.genBaseCity();
    city.LocRandDetec(detective);
    city.genWitnesses();
    city.genHints();
    city.genAlleys();
    printStructs();
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
    collectWitness(next);
}

void Game::setRandomFault() {
    string names[8] = {
        "Carlos", "Diana", "Eduardo", "Fernanda",
        "Gonzalo", "Hilda", "Ivan", "Laura"
    };
    int posc = rand() % 8;
    faultName = names[posc];
    Sospechoso* sospechoso = tablaSospecha.search(faultName);
    if (sospechoso != nullptr) {
        sospechoso->setFault(true);
        cout << "Culpable seleccionado internamente." << endl;
    } else {
        cout << "No se pudo seleccionar culpable." << endl;
    }
}

bool Game::isWitness(char content) {
    return content == 'W';
}

void Game::collectWitness(Location* loc) {
    if (loc == nullptr) {
        return;
    }
    char content = loc->getContent();
    if (!isWitness(content)) {
        return;
    }
    Testigo testigo("Testigo", "Declaracion pendiente del caso");
    colaTestigo.enqueue(testigo);
    cout << "Encontraste un testigo." << endl;
    cout << "Su declaracion fue agregada a la cola." << endl;
    colaTestigo.showAmont();
    loc->setContent(' ');
    loc->setVisible(true);
    loc->setVisita(true);
}

void Game::printControls() {
    cout << endl;
    cout << "Controles disponibles:" << endl;
    cout << "W/A/S/D -> mover detective" << endl;
    cout << "T -> ver pistas recogidas" << endl;
    cout << "X -> usar pista" << endl;
    cout << "V -> ver sospechosos" << endl;
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
    hintsFound++;
    cout << "Has recogido una pista: " << hint.getTypeName() << " (" << type << ")" << endl;
    revealFaultAtrib();
    cout << "Progreso del caso: " << hintsFound << "/10 pistas recogidas." << endl;
    if (hintsFound >= 10) {
        accusPhase = true;
        cout << "Ya reuniste las 10 pistas." << endl;
        cout << "La fase de acusacion esta lista." << endl;
    }
    loc->setContent(' ');
    loc->setVisible(true);
    loc->setVisita(true);
}

void Game::printFinResum(bool solved) {
    cout << endl;
    cout << "========== RESUMEN FINAL ==========" << endl;
    cout << "Detective: " << detective.getName() << endl;
    if (solved) {
        cout << "Resultado: caso resuelto" << endl;
    } else {
        cout << "Resultado: caso fracasado" << endl;
    }
    cout << "Culpable real: " << faultName << endl;
    cout << "Score final: " << detective.getScore() << " movimientos" << endl;
    cout << "Atributos revelados: ";
    if (faultAtribs.empty()) {
        cout << "-";
    } else {
        for (int i = 0; i < faultAtribs.size(); i++) {
            cout << faultAtribs[i];

            if (i < faultAtribs.size() - 1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
    cout << "===================================" << endl;
}

void Game::loadSospechosos() {
    tablaSospecha = HashSospecha();
    tablaSospecha.insert(Sospechoso("Carlos", "alto", "negro", "clara", "recta", "masculino",
                                    "zurdo", "pastuso", "sin cicatriz", "reloj negro", "botas cafes",
                                    "olor a cafe", "taxi", "mochila gris", "estaba en el cafe"));

    tablaSospecha.insert(Sospechoso("Diana", "alta", "rojo", "triguenia", "perfilada", "femenino",
                                    "diestra", "santandereano", "cicatriz mano", "aretes dorados", "tenis blancos",
                                    "olor a perfume dulce", "moto", "carpeta azul", "estaba en el hospital"));

    tablaSospecha.insert(Sospechoso("Eduardo", "medio", "castanio", "morena", "ancha", "masculino",
                                    "diestro", "rolo", "sin cicatriz", "gafas redondas", "zapatos negros",
                                    "olor a humo", "bus", "maletin negro", "estaba en el archivo"));

    tablaSospecha.insert(Sospechoso("Fernanda", "alta", "rubio", "clara", "pequenia", "femenino",
                                    "zurda", "costeno", "cicatriz ceja", "reloj negro", "botas cafes",
                                    "olor a cafe", "taxi", "llavero rojo", "estaba en el callejon"));

    tablaSospecha.insert(Sospechoso("Gonzalo", "bajo", "negro", "morena", "recta", "masculino",
                                    "diestro", "paisa", "cicatriz brazo", "gorra azul", "tenis blancos",
                                    "olor a lluvia", "bicicleta", "mochila gris", "estaba en la esquina"));

    tablaSospecha.insert(Sospechoso("Hilda", "media", "castanio", "clara", "perfilada", "femenino",
                                    "zurda", "pastuso", "sin cicatriz", "collar plata", "zapatos negros",
                                    "olor a perfume dulce", "bus", "sobre amarillo", "estaba en el cafe"));

    tablaSospecha.insert(Sospechoso("Ivan", "alto", "rubio", "triguenia", "ancha", "masculino",
                                    "diestro", "paisa", "cicatriz ceja", "gafas redondas", "botas cafes",
                                    "olor a humo", "moto", "carpeta azul", "estaba en el hospital"));

    tablaSospecha.insert(Sospechoso("Laura", "baja", "rojo", "clara", "pequenia", "femenino",
                                    "diestra", "rolo", "cicatriz mano", "aretes dorados", "tenis blancos",
                                    "olor a lluvia", "taxi", "maletin negro", "estaba en el archivo"));
}

void Game::useHint() {
    if (hintStack.isEmpty()) {
        cout << "No tienes pistas para usar." << endl;
        return;
    }
    Hint hint = hintStack.pop();
    char type = hint.getTipo();
    cout << "Usaste la ultima pista recogida: " << hint.getTypeName() << " (" << type << ")" << endl;
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
    } else if (type == 'P') {
        Location* newPos = city.getRandFreeLoc();
        if (newPos == nullptr) {
            cout << "No hay una ubicacion libre para moverse." << endl;
            return;
        }
        detective.setActPos(newPos);
        newPos->setVisible(true);
        newPos->setVisita(true);
        cout << "La Prueba Forense movio al detective a otra ubicacion." << endl;
    }
    city.relocHint(type, detective.getActPos());
    city.hideMap(detective.getActPos());
}

void Game::playLoop() {
    char opc;
    bool playing = true;
    while (playing) {
        if (accusPhase) {
            startAccusation();
            playing = false;
            continue;
        }
        printControls();
        cout << endl;
        cout << "Ingrese una accion: ";
        cin >> opc;
        opc = toupper(opc);
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
        } else if (opc == 'V') {
            showSospechosos();
            city.printCity(detective);
        } else if (opc == 'I') {
            interrogWitness();
            city.printCity(detective);
        } else {
            cout << "Accion invalida." << endl;
            city.printCity(detective);
        }
    }
}

void Game::startAccusation() {
    string name;
    cout << endl;
    cout << detective.getName() << ", has recolectado las 10 pistas." << endl;
    cout << "Es momento de acusar." << endl;
    showSospechosos();
    cout << endl;
    cout << "Escribe el nombre del sospechoso a acusar: ";
    cin >> name;
    for (int i = 0; i < name.length(); i++) {
        name[i] = tolower(name[i]);
    }
    if (!name.empty()) {
        name[0] = toupper(name[0]);
    }
    int posc = tablaSospecha.getPosc(name);
    cout << endl;
    Sospechoso* accused = tablaSospecha.search(name);
    if (accused == nullptr) {
        cout << "El sospechoso no esta registrado en el caso." << endl;
        cout << "La acusacion se toma como incorrecta." << endl;
        detective.doubScore();
        cout << "Caso cerrado como fracasado." << endl;
        cout << "Puntaje penalizado al doble." << endl;
        cout << "Puntaje final: " << detective.getScore() << " movimientos." << endl;
        printFinResum(false);
        saveFinalScore();
        accusPhase = false;
        return;
    }
    cout << "Nombre encontrado: " << accused->getName() << endl;
    if (accused->getFault()) {
        cout << endl;
        cout << "Caso resuelto. " << accused->getName() << " era el culpable." << endl;
        cout << "Puntaje final: " << detective.getScore() << " movimientos." << endl;
        printFinResum(true);
    } else {
        cout << endl;
        cout << "Acusacion incorrecta." << endl;
        cout << "El culpable real era: " << faultName << endl;
        detective.doubScore();
        cout << "Caso cerrado como fracasado." << endl;
        cout << "Puntaje penalizado al doble." << endl;
        cout << "Puntaje final: " << detective.getScore() << " movimientos." << endl;
        printFinResum(false);
    }
    saveFinalScore();
    accusPhase = false;
}

void Game::showSospechosos() {
    string names[8] = {
        "Carlos", "Diana", "Eduardo", "Fernanda",
        "Gonzalo", "Hilda", "Ivan", "Laura"
    };
    cout << endl;
    cout << detective.getName() << ", sospechosos del caso:" << endl;
    cout << "Atributos del culpable revelados hasta ahora:" << endl;
    if (faultAtribs.empty()) {
        cout << "-" << endl;
    } else {
        for (int i = 0; i < faultAtribs.size(); i++) {
            cout << "- " << faultAtribs[i] << endl;
        }
    }
    cout << endl;
    cout << "Tabla de sospechosos:" << endl;
    for (int i = 0; i < 8; i++) {
        Sospechoso* sosp = tablaSospecha.search(names[i]);
        if (sosp == nullptr) {
            continue;
        }
        vector<string> atribs = sosp->getAtribs();
        cout << sosp->getName() << " | atributos confirmados: ";
        bool found = false;
        for (int j = 0; j < atribs.size(); j++) {
            for (int k = 0; k < faultAtribs.size(); k++) {
                if (atribs[j] == faultAtribs[k]) {
                    if (found) {
                        cout << ", ";
                    }
                    cout << atribs[j];
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "-";
        }
        cout << endl;
    }
}

void Game::interrogWitness() {
    if (colaTestigo.isEmpty()) {
        cout << "No hay testigos pendientes por interrogar." << endl;
        return;
    }
    Testigo testigo = colaTestigo.dequeue();
    cout << "Interrogando al siguiente testigo..." << endl;
    cout << testigo.getName() << ": " << testigo.getDeclar() << endl;
    revealFaultAtrib();
    colaTestigo.showAmont();
}

bool Game::isAtribRevealed(string atrib) {
    for (int i = 0; i < faultAtribs.size(); i++) {
        if (faultAtribs[i] == atrib) {
            return true;
        }
    }
    return false;
}

void Game::saveFinalScore() {
    scoreTree.insert(detective.getName(), detective.getScore());
    cout << "Score guardado correctamente." << endl;
}

void Game::revealFaultAtrib() {
    Sospechoso* fault = tablaSospecha.search(faultName);

    if (fault == nullptr) {
        cout << "No se pudo revelar informacion del culpable." << endl;
        return;
    }

    vector<string> atribs = fault->getAtribs();

    if (faultAtribs.size() >= atribs.size()) {
        cout << "Ya se revelaron todos los atributos disponibles del culpable." << endl;
        return;
    }

    int tries = 0;
    while (tries < 30) {
        int posc = rand() % atribs.size();
        if (!isAtribRevealed(atribs[posc])) {
            faultAtribs.push_back(atribs[posc]);
            cout << "Nuevo dato del culpable: " << atribs[posc] << endl;
            return;
        }
        tries++;
    }
    for (int i = 0; i < atribs.size(); i++) {
        if (!isAtribRevealed(atribs[i])) {
            faultAtribs.push_back(atribs[i]);
            cout << "Nuevo dato del culpable: " << atribs[i] << endl;
            return;
        }
    }
}