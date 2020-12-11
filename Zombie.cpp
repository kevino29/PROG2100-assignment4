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
    auto dir = static_cast<direction>(rand() % NUM_DIRECTIONS);

    switch(dir) {
        case WEST:
            break;
        case NORTH:
            break;
        case EAST:
            break;
        case SOUTH:
            break;
    }
}

void Zombie::convert(Organism& organism) {
}
