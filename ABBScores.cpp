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
