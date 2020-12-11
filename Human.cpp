//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Human.h"

using namespace std;

Human::Human() {
    this->species = "Human";
}

Human::Human(City& city, int x, int y) {
    this->species = "Human";
    this->city = city;
    this->x = x;
    this->y = y;
}

Human::~Human() = default;

void Human::setSpecies(string species) {
    this->species = species;
}

string Human::getSpecies() {
    return this->species;
}

void Human::spawn() {

}

void Human::move() {

}

void Human::recruit() {

}
