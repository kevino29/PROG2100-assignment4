//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Zombie.h"

using namespace std;

Zombie::Zombie() {
    this->species = "Zombie";
    this->moved = false;
    this->eatCooldown = ZOMBIE_STARVE;
    this->convertCooldown = ZOMBIE_BREED;
    this->isConverting = false;
    this->isStarving = false;
}

Zombie::Zombie(City& city, int x, int y) {
    this->species = "Zombie";
    this->city = &city;
    this->x = x;
    this->y = y;
    this->moved = false;
    this->eatCooldown = ZOMBIE_STARVE;
    this->convertCooldown = ZOMBIE_BREED;
    this->isConverting = false;
    this->isStarving = false;
}

Zombie::~Zombie() = default;

void Zombie::setSpecies(string species) {
    this->species = species;
}

string Zombie::getSpecies() {
    return this->species;
}

bool Zombie::isStarving1() const {
    return isStarving;
}

void Zombie::setIsStarving(bool isStarving) {
    Zombie::isStarving = isStarving;
}

int Zombie::getConvertCooldown() const {
    return convertCooldown;
}

void Zombie::setConvertCooldown(int convertCooldown) {
    Zombie::convertCooldown = convertCooldown;
}

bool Zombie::isConverting1() const {
    return isConverting;
}

void Zombie::setIsConverting(bool isConverting) {
    Zombie::isConverting = isConverting;
}

void Zombie::move() {
    Organism *organism = nullptr;

    if (rand() % 2 == 0) {
        auto dir = static_cast<cardinal_direction>(rand() % NUM_CARDINAL_DIRECTIONS);

        switch(dir) {
            case WEST:
                if (x != 0) {
                    if (this->city->getOrganism(this->x - 1, this->y) == nullptr ||
                        this->city->getOrganism(this->x - 1, this->y)->getSpecies() == "Human") {
                        if (this->city->getOrganism(this->x - 1, this->y) != nullptr &&
                            this->city->getOrganism(this->x - 1, this->y)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x, this->y - 1) != nullptr &&
                            this->city->getOrganism(this->x, this->y - 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x + 1, this->y) != nullptr &&
                            this->city->getOrganism(this->x + 1, this->y)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x, this->y + 1) != nullptr &&
                            this->city->getOrganism(this->x, this->y + 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x - 1, this->y - 1) != nullptr &&
                            this->city->getOrganism(this->x - 1, this->y - 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x + 1, this->y - 1) != nullptr &&
                            this->city->getOrganism(this->x + 1, this->y - 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x + 1, this->y + 1) != nullptr &&
                            this->city->getOrganism(this->x + 1, this->y + 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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
                        if (this->city->getOrganism(this->x - 1, this->y + 1) != nullptr &&
                            this->city->getOrganism(this->x - 1, this->y + 1)->getSpecies() == "Human")
                            eatCooldown = ZOMBIE_STARVE;
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

    if (convertCooldown > 0) {
        isConverting = false;
        convertCooldown--;

        if (convertCooldown == 0) {
            isConverting = true;
        }
    }

    if (eatCooldown > 0) {
        isStarving = false;
        eatCooldown--;

        if (eatCooldown == 0)
            isStarving = true;
    }
}

string Zombie::convert() {
    convertCooldown = HUMAN_BREED;
    isConverting = true;

    // Check NORTH
    if (y != 0) {
        if (this->city->getOrganism(this->x, this->y - 1) == nullptr ||
            this->city->getOrganism(this->x, this->y - 1)->getSpecies() == "Human") {
            return "NORTH";
        }
    }
    // Check SOUTH
    if (y != GRID_HEIGHT - 1) {
        if (this->city->getOrganism(this->x, this->y + 1) == nullptr ||
            this->city->getOrganism(this->x, this->y + 1)->getSpecies() == "Human") {
            return "SOUTH";
        }
    }
    // Check EAST
    if (x != (GRID_WIDTH - 1)) {
        if (this->city->getOrganism(this->x + 1, this->y) == nullptr ||
            this->city->getOrganism(this->x + 1, this->y)->getSpecies() == "Human") {
            return "EAST";
        }
    }
    // Check WEST
    if (x != 0) {
        if (this->city->getOrganism(this->x - 1, this->y) == nullptr ||
            this->city->getOrganism(this->x - 1, this->y)->getSpecies() == "Human") {
            return "WEST";
        }
    }
    // Check NORTHWEST
    if (y != 0 && x != 0) {
        if (this->city->getOrganism(this->x - 1, this->y - 1) == nullptr ||
            this->city->getOrganism(this->x - 1, this->y - 1)->getSpecies() == "Human") {
            return "NORTHWEST";
        }
    }
    // Check NORTHEAST
    if (y != 0 && x != (GRID_WIDTH - 1)) {
        if (this->city->getOrganism(this->x + 1, this->y - 1) == nullptr ||
            this->city->getOrganism(this->x + 1, this->y - 1)->getSpecies() == "Human") {
            return "NORTHEAST";
        }
    }
    // Check SOUTHEAST
    if (y != (GRID_HEIGHT - 1) && x != (GRID_WIDTH - 1)) {
        if (this->city->getOrganism(this->x + 1, this->y + 1) == nullptr ||
            this->city->getOrganism(this->x + 1, this->y + 1)->getSpecies() == "Human") {
            return "SOUTHEAST";
        }
    }
    // Check SOUTHWEST
    if (x != 0 && y != GRID_HEIGHT - 1) {
        if (this->city->getOrganism(this->x - 1, this->y + 1) == nullptr ||
            this->city->getOrganism(this->x - 1, this->y + 1)->getSpecies() == "Human") {
            return "SOUTHWEST";
        }
    }

    convertCooldown = 0;
    isConverting = false;
    return "NONE";
}

void Zombie::starve() {

}
