//
// Created by Kevin on 12/11/2020.
//

#include "Organism.h"

using namespace std;

Organism::Organism() {}

Organism::Organism(City& city, int x, int y) {
    this->city = &city;
    this->x = x;
    this->y = y;
}

Organism::~Organism() = default;

//string Organism::getSpecies() {
//    return this->species;
//}

int Organism::getX() const {
    return this->x;
}

void Organism::setX(int mX) {
    this->x = mX;
}

int Organism::getY() const {
    return this->y;
}

void Organism::setY(int mY) {
    this->y = mY;
}

int Organism::getTurns() const {
    return this->turns;
}

void Organism::setTurns(int mTurns) {
    this->turns = mTurns;
}

void Organism::setCity(City *mCity) {
    this->city = mCity;
}

int Organism::getRandomInt(int min, int max) {
    return rand() % max + min;
}

bool Organism::isTurn() {

}

void Organism::endTurn() {

}

ostream& operator<<(ostream &output, Organism *organism) {

}