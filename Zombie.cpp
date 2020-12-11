//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Zombie.h"
#include "Human.h"

using namespace std;

Zombie::Zombie() {
    this->species = "Zombie";
}

Zombie::Zombie(City city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

Zombie::~Zombie() = default;

void Zombie::setSpecies(string species) {
    this->species = species;
}

string Zombie::getSpecies() {
    return this->species;
}

void Zombie::spawn() {

}

void Zombie::move() {

}

void Zombie::convert(Organism& organism) {
}
