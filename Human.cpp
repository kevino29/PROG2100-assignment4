//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Human.h"

using namespace std;

Human::Human() {
    this->species = "Human";
}

Human::Human(City *city, int width, int height) {
    this->species = "Human";
    this->city = city;
    this->width = width;
    this->height = height;
}

Human::~Human() = default;

void Human::spawn() {

}

void Human::move() {

}

string Human::getSpecies() {
    return this->species;
}