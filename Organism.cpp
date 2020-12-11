//
// Created by Kevin on 12/11/2020.
//

#include "Organism.h"

using namespace std;

Organism::Organism() {}

Organism::Organism(City city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

Organism::~Organism() = default;

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

void Organism::endTurn() {

}

bool Organism::isTurn() {

}

ostream& operator<<(ostream &output, Organism *organism) {

}
