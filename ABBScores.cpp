#include "ABBScores.h"

ScoreNode::ScoreNode(string nameDetective, int score) {
    this->nameDetective = nameDetective;
    this->score = score;
    left = nullptr;
    right = nullptr;
}

string ScoreNode::getDetecName() {
    return nameDetective;
}

void ScoreNode::setDetecName(string nameDetective) {
    this->nameDetective = nameDetective;
}

int ScoreNode::getScore() {
    return score;
}

void ScoreNode::setScore(int score) {
    this->score = score;
}

ScoreNode* ScoreNode::getLeft() {
    return left;
}

void ScoreNode::setLeft(ScoreNode* left) {
    this->left = left;
}

ScoreNode* ScoreNode::getRight() {
    return right;
}

void ScoreNode::setRight(ScoreNode* right) {
    this->right = right;
}

ABBScores::ABBScores() {
    root = nullptr;
}

ABBScores::~ABBScores() {
    freeRecurs(root);
}

void ABBScores::insert(string nameDetective, int score) {
    ScoreNode* prev = search(nameDetective);
    if (prev != nullptr) {
        if (score >= prev->getScore()) {
            cout << nameDetective << " ya tenia un mejor score: "
                 << prev->getScore() << " puntos." << endl;
            cout << "Nuevo score no guardado: " << score << " puntos." << endl;
            return;
        }
        int oldScore = prev->getScore();
        root = deleteScoreNode(root, nameDetective, oldScore);
        cout << nameDetective << " mejoro su score." << endl;
        cout << "Score anterior: " << oldScore << endl;
        cout << "Nuevo mejor score: " << score << endl;
    }
    root = recursInsert(root, nameDetective, score);
}

ScoreNode* ABBScores::recursInsert(ScoreNode* act, string nameDetective, int score) {
    if (act == nullptr) {
        return new ScoreNode(nameDetective, score);
    }
    if (score < act->getScore()) {
        act->setLeft(recursInsert(act->getLeft(), nameDetective, score));
    } else {
        act->setRight(recursInsert(act->getRight(), nameDetective, score));
    }
    return act;
}

ScoreNode* ABBScores::search(string nameDetective) {
    return searchRecurs(root, nameDetective);
}

ScoreNode* ABBScores::searchRecurs(ScoreNode* act, string nameDetective) {
    if (act == nullptr) {
        return nullptr;
    }
    if (act->getDetecName() == nameDetective) {
        return act;
    }
    ScoreNode* foundLeft = searchRecurs(act->getLeft(), nameDetective);

    if (foundLeft != nullptr) {
        return foundLeft;
    }
    return searchRecurs(act->getRight(), nameDetective);
}

ScoreNode* ABBScores::minNode(ScoreNode* act) {
    if (act == nullptr) {
        return nullptr;
    }
    while (act->getLeft() != nullptr) {
        act = act->getLeft();
    }
    return act;
}

void ABBScores::printOrdered() {
    cout << "Historico de puntajes de menor a mayor:" << endl;
    printRecursOrd(root);
}

void ABBScores::printRecursOrd(ScoreNode* act) {
    if (act == nullptr) {
        return;
    }
    printRecursOrd(act->getLeft());
    cout << act->getDetecName() << " | " << act->getScore() << " puntos" << endl;
    printRecursOrd(act->getRight());
}

void ABBScores::freeRecurs(ScoreNode* act) {
    if (act == nullptr) {
        return;
    }
    freeRecurs(act->getLeft());
    freeRecurs(act->getRight());
    delete act;
}

ScoreNode* ABBScores::deleteScoreNode(ScoreNode* act, string nameDetective, int score) {
    if (act == nullptr) {
        return nullptr;
    }
    if (score < act->getScore()) {
        act->setLeft(deleteScoreNode(act->getLeft(), nameDetective, score));
    } else if (score > act->getScore()) {
        act->setRight(deleteScoreNode(act->getRight(), nameDetective, score));
    } else {
        if (act->getDetecName() != nameDetective) {
            act->setRight(deleteScoreNode(act->getRight(), nameDetective, score));
            return act;
        }
        if (act->getLeft() == nullptr && act->getRight() == nullptr) {
            delete act;
            return nullptr;
        }
        if (act->getLeft() == nullptr) {
            ScoreNode* aux = act->getRight();
            delete act;
            return aux;
        }
        if (act->getRight() == nullptr) {
            ScoreNode* aux = act->getLeft();
            delete act;
            return aux;
        }
        ScoreNode* aux = minNode(act->getRight());
        act->setDetecName(aux->getDetecName());
        act->setScore(aux->getScore());
        act->setRight(deleteScoreNode(act->getRight(), aux->getDetecName(), aux->getScore()));
    }
    return act;
}