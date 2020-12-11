//
// Created by Kevin on 12/11/2020.
//

#include "Organism.h"

using namespace std;

Organism::Organism() {}

Organism::Organism(City *city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

Organism::~Organism() = default;

void Organism::setPosition(int x, int y) {

}

void Organism::endTurn() {

}

bool Organism::isTurn() {

}

ostream& operator<<( ostream &output, Organism *organism ) {

}
