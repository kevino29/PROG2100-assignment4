//
// Created by Kevin on 12/11/2020.
//

#include <string>
#include "Human.h"

using namespace std;

Human::Human() {
    this->species = "Human";
    this->moved = false;
}

Human::Human(City& city, int x, int y) {
    this->species = "Human";
    this->city = &city;
    this->x = x;
    this->y = y;
    this->moved = false;
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
    Organism *organism = nullptr;
    while (!moved) {
        auto dir = static_cast<direction>(rand() % NUM_DIRECTIONS);

        switch(dir) {
            case WEST:
                cout << "WEST" << endl;
                if (x != 0) {
                    if (this->city->getOrganism(this->x - 1, this->y) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x -= 1;
                        moved = true;
                    }
                }
                break;
            case NORTH:
                cout << "NORTH" << endl;
                if (y != 0) {
                    if (this->city->getOrganism(this->x, this->y - 1) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->y -= 1;
                        moved = true;
                    }
                }
                break;
            case EAST:
                cout << "EAST" << endl;
                if (x != (GRID_WIDTH - 1)) {
                    if (this->city->getOrganism(this->x + 1, this->y) == nullptr) {
                        this->city->setOrganism(*organism, this->x, this->y);
                        this->x += 1;
                        moved = true;
                    }
                }
                break;
            case SOUTH:
                cout << "SOUTH" << endl;
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

void Human::recruit() {

}
