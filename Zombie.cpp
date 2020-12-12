//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Zombie.h"
#include "Human.h"

using namespace std;

Zombie::Zombie() {
    this->species = "Zombie";
    this->moved = false;
}

Zombie::Zombie(City& city, int x, int y) {
    this->species = "Zombies";
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

void Zombie::spawn() {

}

void Zombie::move() {
    Organism *organism = nullptr;
    while (!moved) {
        auto dir = static_cast<direction>(rand() % NUM_DIRECTIONS);

        switch(dir) {
            case WEST:
                if (x != 0) {
                    if (this->city->getOrganism(this->x - 1, this->y) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x -= 1;
                        moved = true;
                    }
                }
                break;
            case NORTH:
                if (y != 0) {
                    if (this->city->getOrganism(this->x, this->y - 1) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->y -= 1;
                        moved = true;
                    }
                }
                break;
            case EAST:
                if (x != (GRID_WIDTH - 1)) {
                    if (this->city->getOrganism(this->x + 1, this->y) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x += 1;
                        moved = true;
                    }
                }
                break;
            case SOUTH:
                if (y != GRID_HEIGHT - 1) {
                    if (this->city->getOrganism(this->x, this->y + 1) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->y += 1;
                        moved = true;
                    }
                }
                break;
            case NUM_DIRECTIONS:
                break;
        }
        if (moved)
            this->city->setOrganism((Organism &) *this, this->x, this->y);
    }
    moved = false;
}

void Zombie::convert(Organism& organism) {

}
