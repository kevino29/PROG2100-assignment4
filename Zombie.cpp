//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Zombie.h"

using namespace std;

Zombie::Zombie() {
    this->species = "Zombie";
    this->moved = false;
}

Zombie::Zombie(City& city, int x, int y) {
    this->species = "Zombie";
    this->city = &city;
    this->x = x;
    this->y = y;
    this->moved = false;
}

Zombie::~Zombie() = default;

void Zombie::setSpecies(string species) {
    this->species = species;
}

string Zombie::getSpecies() {
    return this->species;
}

void Zombie::spawn() {}

void Zombie::move() {
    Organism *organism = nullptr;

    if (rand() % 2 == 0) {
        auto dir = static_cast<cardinal_direction>(rand() % NUM_CARDINAL_DIRECTIONS);

        switch(dir) {
            case WEST:
                if (x != 0) {
                    if (this->city->getOrganism(this->x - 1, this->y) == nullptr ||
                        this->city->getOrganism(this->x - 1, this->y)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x -= 1;
                        moved = true;
                    }
                }
                break;
            case NORTH:
                if (y != 0) {
                    if (this->city->getOrganism(this->x, this->y - 1) == nullptr ||
                        this->city->getOrganism(this->x, this->y - 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->y -= 1;
                        moved = true;
                    }
                }
                break;
            case EAST:
                if (x != (GRID_WIDTH - 1)) {
                    if (this->city->getOrganism(this->x + 1, this->y) == nullptr ||
                        this->city->getOrganism(this->x + 1, this->y)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x += 1;
                        moved = true;
                    }
                }
                break;
            case SOUTH:
                if (y != GRID_HEIGHT - 1) {
                    if (this->city->getOrganism(this->x, this->y + 1) == nullptr ||
                        this->city->getOrganism(this->x, this->y + 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->y += 1;
                        moved = true;
                    }
                }
                break;
            case NUM_CARDINAL_DIRECTIONS:
                break;
        }
    }
    else {
        auto dir = static_cast<ordinal_direction>(rand() % NUM_ORDINAL_DIRECTIONS);

        switch(dir) {
            case NORTHWEST:
                if (y != 0 && x != 0) {
                    if (this->city->getOrganism(this->x - 1, this->y - 1) == nullptr ||
                        this->city->getOrganism(this->x - 1, this->y - 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x -= 1;
                        this->y -= 1;
                        moved = true;
                    }
                }
                break;
            case NORTHEAST:
                if (y != 0 && x != (GRID_WIDTH - 1)) {
                    if (this->city->getOrganism(this->x + 1, this->y - 1) == nullptr ||
                        this->city->getOrganism(this->x + 1, this->y - 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x += 1;
                        this->y -= 1;
                        moved = true;
                    }
                }
                break;
            case SOUTHEAST:
                if (y != (GRID_HEIGHT - 1) && x != (GRID_WIDTH - 1)) {
                    if (this->city->getOrganism(this->x + 1, this->y + 1) == nullptr ||
                        this->city->getOrganism(this->x + 1, this->y + 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x += 1;
                        this->y += 1;
                        moved = true;
                    }
                }
                break;
            case SOUTHWEST:
                if (x != 0 && y != GRID_HEIGHT - 1) {
                    if (this->city->getOrganism(this->x - 1, this->y + 1) == nullptr ||
                        this->city->getOrganism(this->x - 1, this->y + 1)->getSpecies() == "Human") {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x -= 1;
                        this->y += 1;
                        moved = true;
                    }
                }
                break;
            case NUM_ORDINAL_DIRECTIONS:
                break;
        }
    }
    if (moved) {
        this->city->setOrganism((Organism &) *this, this->x, this->y);
        moved = false;
    }
}

void Zombie::convert() {

}
